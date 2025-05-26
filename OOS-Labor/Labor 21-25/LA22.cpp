
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]) {
    double d = 1.234;
    cout << " Nr Oct  Hex String  Fixed     Scientific " << endl;
    for (int k = 1; k < 11; k++)
    {
        cout << right << noshowpos << dec << setw(3)  << k;
        cout << right << nouppercase << setw(4) << showbase << oct << k;
        cout << hex << setw(5) << k << " ";
        cout <<  left << string(k % 5 + 1, '*') << string(6 - (k % 5 + 1), '+') << '+'  << " ";
        cout << setw(9) <<setfill(' ')<< fixed<< internal << setprecision(3)<< showpos<<  d;
        cout << noshowpos<<uppercase<< right<<scientific<<setw(11) << d;
        d = d*-2;

        cout << endl;
    }
    return 0;
}

