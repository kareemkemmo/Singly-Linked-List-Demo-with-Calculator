#include "CalcList.hpp"

CalcList::CalcList(){
    //constructor creates empty singly linked list by setting head to NULL
    head = NULL;
    size = 0;
}
CalcList::~CalcList(){
    //destructor removes the last operation till the CalcList is empty
    while (!empty()) removeLastOperation();
}
bool CalcList::empty(){
    //empty function returns true if head points to NULL
    if (head == NULL){
        return true;
    }
    //returns false if head doesnt point to NULL
    else {
        return false;
    }
}
double CalcList::total() const{
    //if list is empty the total is 0
    if (head == NULL) {
        return 0;
    }
    //if the list is not empty then the total till that point is stored in the total value of the head pointer
    else {
        return head -> total;
    }
}
void CalcList::newOperation(const FUNCTIONS func, const double operand){
    size += 1;
    CalcNode* c = new CalcNode;
    //set func and operand
    c->func = func;
    c->operand = operand;
    //check for last total and perform operation on it
    //set as new total for new CalcNode
    if (func == 0){
        c->total = total() + operand;
    }
    else if (func == 1){
        c->total = total() - operand;
    }
    else if (func == 2){
        c->total = total() * operand;
    }
    else if (func == 3){
        if (operand == 0) {
            throw std::runtime_error("Math error: Attempted to divide by Zero\n");
        }
        c->total = total() / operand;
    }
    //point next to current head
    c->next = head;
    //point head to this calcnode
    head = c;
}
void CalcList::removeLastOperation(){
    if (empty()) {
        throw std::runtime_error("Task error: Attempted to remove from empty list\n");
    }
    size -= 1;
    //store current head in temp variable
    CalcNode* old = head;
    //go to next CalcNode after head
    //set head to that CalcNode
    head = old->next;
    //delete old head using the temp variable pointer
    delete old;
}
std::string CalcList::toString(unsigned short precision) const{
    //iterate through the list adding and adding its data to the output stream
    int step = size;
    CalcNode* iterator = head;
    std::ostringstream oss;
    while (step != 0) {
        oss << std::fixed << std::setprecision(0);
        oss << step;
        oss << ": ";
        oss << std::setprecision(precision);
        if (iterator->next != NULL) {
            oss << iterator->next->total;
        }
        else{
            oss << 0.00;
        }

        if (iterator->func == 0){
            oss << '+';
        }
        else if (iterator->func == 1){
            oss << '-';
        }
        else if (iterator->func == 2){
            oss << '*';
        }
        else if (iterator->func == 3){
            oss << '/';
        }
        oss << iterator->operand;
        oss << "=";
        oss << iterator->total;
        oss << "\n";
        if (iterator->next != NULL) {
            iterator = iterator->next;
        }
        step -= 1;
    }
    return oss.str();

    //finally correctly adjust the precision
    //return string
}
