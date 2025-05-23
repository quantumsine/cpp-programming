
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]) {
    double d = 1.234;
    cout << " Nr Oct  Hex String  Fixed     Scientific " << endl;
    for (int k = 1; k < 11; k++)
    {
        cout << right << setw(3) << dec << noshowpos  << k;
        cout << right << setw(3) << "0" << oct << k;
        cout << " 0x"  << hex << k << " ";
        cout << " " <<  string(k % 5 + 1, '*') << string(6 - (k % 5 + 1), '+')  << " ";
        cout << " " << fixed << right << showpos << setfill(' ') << setw(9) << setprecision(3) << internal << d;
        cout << " " << scientific << uppercase << setprecision(3) << d;
        d = d*-2;

        cout << endl;
    }
    return 0;
}

