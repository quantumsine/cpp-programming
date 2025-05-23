#include <iostream>
#include <string>
using namespace std;


/*  Sie können nur auf statische Datenelement zugreifen und verfügen keine this-Zeiger. 
    Auch wenn es noch kein Objekt in der Klasse gibt, können sie aufgerufen werden
    Wie oben beschrieben werden sie mithilfe des Scope-Operators aufgerufen.
*/

class Car_stats {
    private:
    string car_name;
    static int car_year;
    
    public:
    static void set_car_year(int car_year){ // Problem: beim Aufruf wird das Datenelement verdeckt
        // car_year = car_year; --> Namenskollision, da car_year statisch ist
        car_year = car_year;

        //Stattdessen:
        // Car_stats::car_year = car_year;
    }

    static int get_car_year(){
        return car_year;
        }
};

int Car_stats::car_year = 2020;

int main(int argc, char const *argv[])
{
    Car_stats year;
    Car_stats::set_car_year(2021); // Keine Änderung, siehe Namenskollision
    cout << Car_stats::get_car_year() << endl;
    
    return 0;
}
