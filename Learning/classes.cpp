#include <iostream>
#include <string>
using namespace std;

// Classes, erweriterte Version von Datenstrukturen, wobei man damit Objekte erstellen kann

class my_car{ //Erstellung einer Klasse
    public:
        string car_brand; // Variablen, die in der Klasse definiert werden
        string car_model;
        int car_year;

        // Struktur, die zum Aufruf des Objektes erstellt wird.

        // Struktur zur Eingabe der Daten
        void set_car_brand(string brand){
            car_brand = brand;
        }
        void set_car_model(string model){
            car_model = model;
        }
        
        string get_car_brand(){
            return car_brand;
        }

        // Struktur zur Ausgabe der Daten
        void print(){
            std::cout << "Name of Car: " << car_brand << std::endl;
            std::cout << "Model: " << car_model << std::endl;
            std::cout << "Year: " << car_year << std::endl;
        }
};

// Ausgabe durch Funktionsaufruf in der Main-Funktion:
int main(int argc, char const *argv[])
{
    my_car car1;
    car1.set_car_brand("BMW");
    car1.set_car_model("X5");
    car1.car_year = 2015;
    car1.print();

    std::cout << car1.get_car_brand() << std::endl;
    return 0;
}
