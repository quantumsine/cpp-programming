#include <iostream>
#include <string>

using namespace std;

// Konstruktoren:  Methode innerhalb einer Klasse, die automatisch aufgerufen wird, wenn ein Objekt erstellt wird:

class Car_Brand{
    private:
        string brand;
        int model_yr;

        public:

        // Konstruktorarten: Parametrisierter Konstruktor
            Car_Brand(string automarke, int baujahr){
                brand = automarke;
                model_yr = baujahr;
            }
        // Standardkonstruktor
        Car_Brand(){
            brand = "Unbekannt";
            model_yr = 0;
        }

        //Kopierkonstruktor (Kopie des Objekts "automarke")
        Car_Brand(string automarke){
            brand = automarke;
            model_yr = 0;
        }

        void display(){
            cout << "Marke: " << brand << ", Baujahr: " << model_yr << endl;
        }
};

int main(int argc, char const *argv[])
{
    Car_Brand mein_auto("Audi RS7", 2021 );
    Car_Brand("BMW M5", 2020 );
    mein_auto.display();
    return 0;
}