#include <iostream>
using namespace std;

#include "Employee.h"
#include "Manager.h"
#include "Worker.h"

int main()
{
    Manager m("Lionel", "Toussoumsnaba", 1000.00);
    m.print();
    cout << "Gehalt: " << m.get_income() << endl << endl;
    Worker w("Rainer", "Mueller", 15.00, 40);
    w.print();
    cout << "Lohn: " << w.get_income() << endl;
    return 0;
}