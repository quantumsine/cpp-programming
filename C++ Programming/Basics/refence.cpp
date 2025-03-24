#include <iostream>

using namespace std;

// Eine Referenz funktioniert als einen Alias für eine bestehende Variable. 
// Sie ist eine Möglichkeit, auf eine Variable zuzugreifen, ohne ihre Adresse direkt zu nutzen.

void reference_example(){
    int x = 10; 
    int &ref = x; // Eine Referenz auf x

    std::cout << "x:  " << x << std::endl; // Ausgabe: 10
    std::cout << "ref:  " << ref << std::endl; // Ausgabe: 10

    ref = 25;

    std::cout << "x nach Änderung: " << x << std::endl; // Ausgabe: 25
}

//Referenzen können auch als Funkionsparameter, um Variablen zu übergeben, ohne sie zu kopieren
void reference_parameter(int& y){
    y = 25;
}

int main(int argc, char const *argv[])
{
    reference_example();

    int num = 10;
    std::cout << "num vor Aufruf: " << num << std::endl;
    reference_parameter(num);
    std::cout << "num nach Aufruf: " << num << std::endl;
    return 0;
}
