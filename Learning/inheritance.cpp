#include <iostream>

/*Vererbung = Eine Klasse, die Eigenschaften und Fähigkeiten  einer anderen Klasse übernimmt.
            Ableitende Klassen übernnehmen die Eigenschaften und Fähigkeiten der Basisklasse.*/


class Car { 
    private:
    bool is_electric;
    // static int instance_count; // Vorerst sicherstellen, dass Die Erstellung und Zerstörung des Objektes der Basiskl. nur 1x vorkommt

    public:
    int max_speed;

    protected:
    int max_power;

    public:
    //Fähigkeiten (Methode) mit Konstruktoren

    // Defaultkonstruktor
    Car(){
        is_electric = false;
        max_speed = 0;
        max_power = 0;
        std:: cout << "Car-Datei wurde erstellt" << std::endl;

    }

    Car(bool engine, int vmax, int power): is_electric(engine), max_speed(vmax), max_power(power) {
      
    }


    ~Car(){
        std::cout << "Car-Datei ist zerstört." << std::endl;
    }

    void print(){
        std::cout << "Max. Geschwindigkeit: " << max_speed << std::endl;
        std::cout << "Max. Power: " << max_power << std::endl;

        if (is_electric) {
            std::cout << "Dies ist ein elektrisches Auto." << std::endl;
        }
    }
};

// Private, protected und public-Vererbung:

/*Public-Vererbung: Alle public- und protected-Attribute  werden in der Klasse unverändert vererbt.
  Protected-Vererbung: Alle public- und protected-Attribute der Klasse werden als protected vererbt.
  Private-Vererbung: Alle public- und protected-Attribute der Klasse werden als private vererbt.*/

  class ElectricCar : public Car {
    // Zugriff auf der Klasse Car
    public:

    // Auch hier: Defaultkonstruktor
    ElectricCar(){
        max_power = 1000; // Zugriff auf protected-Attribute
        max_speed = 260; // Zugriff auf public-Attribute
        // is_electric = true; // Fehler! Wir greifen auf die private-Attribute zu!
    }

    ElectricCar(int vmax, int power): Car(true, vmax, power){
        std::cout << "ElectricCar-Datei ist erstellt." << std::endl;

    }

    ~ElectricCar(){
        std::cout << "ElectricCar-Datei ist zerstört." << std::endl;
    }

    // Bei der Vererbung können wir auch klassen erweitern:
    void e_print(){
       
        std::cout << "Max. Geschwindigeit des E-Autos: " << max_speed << std::endl;
        std::cout << "Max. Power: " << max_power << std::endl;
    }
  };


  class Hydrogen_car : protected Car {
    // Zugriff auf der Klasse Car
    public:
    Hydrogen_car(){
        max_power = 450; // Zugriff auf protected-Attribute
        max_speed = 220; // Zugriff auf public-Attribute
    }

    Hydrogen_car(int vmax, int power) : Car(false, vmax, power){
        std::cout << "Hydrogen_car-Datei ist erstellt." << std::endl;

    }



    ~Hydrogen_car(){
        std::cout << "Hydrogen_car-Datei ist zerstört." << std::endl;
    }

    void h_print(){
        std::cout << "Max. Geswchwindigkeit des H2-Autos: " << max_speed << std::endl;
        std::cout << "Max. Power: " << max_power << std::endl;
    }
  };


  class Diesel_car : private Car {
    // Zugriff auf der Klasse Car
    public:
    Diesel_car(){
        max_power = 200; // Zugriff auf protected-Attribute
        max_speed = 180; // Zugriff auf public-Attribute
    }

    Diesel_car(int vmax, int power): Car(false, vmax, power){
        std::cout << "Diesel_car-Datei ist erstellt." << std::endl;
    }

    ~Diesel_car(){
        std::cout << "Diesel_car-Datei ist zerstört." << std::endl;
    }

    void d_print(){
        std::cout << "Max. Geschwindigkeit des Diesels: " << max_speed << std::endl;
        std::cout << "Max. Power: " << max_power << std::endl;
    }
  };



  int main(int argc, char const *argv[])
  {
    // Verwendung der klasse durch Objekte
    Car car(true, 260, 312); // True hier verwendbar, da die private-Attribute noch zugänglich ist.
    car.print();

    ElectricCar mercedes_eqe(210, 292);
    mercedes_eqe.e_print();

    Hydrogen_car toyota_mirai(220, 182);
    toyota_mirai.h_print();

    Diesel_car audi_a4(225, 200);
    audi_a4.Diesel_car::d_print();

    //Objekt ohne fest gesetzte Daten -> Nutzung Defaultkonstruktor (Ausgabe auch vom Konstruktor Car())
    Diesel_car bmw_5_series;
    bmw_5_series.Diesel_car::d_print();
    
    return 0;
  }
  