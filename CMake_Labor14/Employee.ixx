export module Employee;
import <string>;
import <iostream>;
using namespace std;


export class Employee
{
protected:
    string _first_name;
    string _last_name;

public:
    Employee(const string f_n, const string l_n)
    {
        _first_name = f_n;
        _last_name = l_n;
    }
    void print() const
    {
        cout << _last_name << ", " << _first_name << endl;
    }
};
