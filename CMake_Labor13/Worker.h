#include <string>
using namespace std;

#ifndef WORKER_H
#define WORKER_H

class Worker: public Employee
{
    double _hourly_earnings;
    double _hours;

public:
    Worker(const string, const string, double = 0.0, double = 0.0);
    double get_income() const;
    void print() const;
};

#endif