#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

#include <string>
using namespace std;

class Manager: public Employee {
    double _salary;

public:
    Manager(const string, const string, double);
    double get_income() const;
    void print() const;
};  

#endif