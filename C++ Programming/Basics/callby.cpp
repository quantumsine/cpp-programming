#include <iostream>

using namespace std;

// Call-By-Value: Hier wird eine Kopie eines Arguments an die Funktion übergeben.
// Änderungen innerhalb der Funktion haben keinerlei Auswirkungen auf die Originalvariable:

void change_value(int num){ // num eine Kopie der Originalvariable
    num = 10;
}
/* Vor/Nacteile:
    + Sicher, da Kopie erstellt wird
    + kein außergewöhnliches Verhalten bei der Ausführung
    - Langsam für große Objekte
    */



// Call-By-Refence: Hier wird ein Argument durch die Referenz auf die Funktion übergeben.
// Dabei wird die Variable nicht kopiert, heißt: Die Orginalvariable kann jederzeit verändert werden.

void increment_by_reference(int& num_ref){ // num_ref eine Referenz auf die Originalvariable
    num_ref++;
}
/* Vor/Nacteile:
    + Schnell, keine Kopie wird erstellt
    + Variable kann direkt verändert werden 
    - Veränderungen können unabsichtlich passieren*/


int main(int argc, char const *argv[])
{
    int num = 5;
    int num2 = 7;
    cout << "Vor Aufruf : "<< num << endl;
    change_value(num); // num bleibt unverändert
    cout << "Nach Aufruf : "<< num << endl;


    cout << "Ausgabe vor Inkrementierung : "<< num2 << endl;
    increment_by_reference(num2); 
    cout << "Ausgabe nach Inkrementierung : "<< num2 << endl;

    return 0;
}


