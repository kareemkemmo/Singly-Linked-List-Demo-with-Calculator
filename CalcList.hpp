#ifndef CALCLIST_H
#define CALCLIST_H

#include "CalcListInterface.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

class CalcNode {
private:
    FUNCTIONS func;
    double operand;
    double total;
    CalcNode *next;

friend class CalcList;
};

class CalcList: public CalcListInterface {
    public:
    CalcList();
    ~CalcList();
    bool empty();
    double total() const;
    void newOperation(const FUNCTIONS func, const double operand);
    void removeLastOperation();
    std::string toString(unsigned short precision) const;
    private:
    CalcNode* head;
    int size;
};

#endif 