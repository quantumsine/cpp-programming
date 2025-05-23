#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class Exception{
  public:
    virtual const char* what() const noexcept = 0;
    ~Exception(){}
};

// Eigene Exceptionklasse "MyException"
// abgeleitet von Exception
class MyException: public Exception{
    const char* _dateiname;
    int _zeile;
    string _beschreibung;
    string _meldung;
    public:
      MyException(const char* dateiname, int zeile, string beschreibung): _dateiname(dateiname), _zeile(zeile), _beschreibung(beschreibung){
        _meldung = "Fehler '" + _beschreibung + "' aufgetreten in Datei " + _dateiname + ", Zeile: " + std::to_string(_zeile) + ".";

      }
      void print(){
          cout << "Fehler in Datei " << _dateiname << " bei Zeile " << _zeile << ": " << _beschreibung << endl;
      }
        const char* what() const noexcept override{
          return _meldung.c_str();
        }


};

// Eigene Exceptionklasse "ElefantMeetsMouse"
// abgeleitet von MyException
class ElefantMeetsMouse: public MyException {
  public:
    ElefantMeetsMouse(const char* dateiname, int zeile, const string& beschreibung): MyException(dateiname, zeile, "Elefant trifft auf Maus"){}
};

// Klasse der Tiere
class Animal
{
    // Name des Tiers
    string _name;

public:
    // Konstruktor
    Animal()
    {
        cout << "Bitte Namen des Tieres eingeben: ";
        cin >> _name;
    };
    // virtuelle print-Funktion
    virtual void print(bool nl) const
    {
        cout << _name;
        if (nl)
        {
            cout << endl;
        }
    }
    virtual Animal *clone() const = 0;
};

// Klasse "Elefant"
// abgeleitet von Animal
class Elefant: public Animal {
    public:
      Elefant* clone() const override {
        return new Elefant(*this);
      }
};

// Klasse "Tiger"
// abgeleitet von Animal
class Tiger: public Animal {
  public:
    Tiger* clone() const override {
      return new Tiger(*this);
    }
};

// Klasse "Mouse"
// abgeleitet von Animal
class Mouse: public Animal {
  public:
    Mouse* clone() const override {
      return new Mouse(*this);
    }
};

class Zoo
{
    // Name des Zoos
    string _name;
    // Die Tiere werden in einem Vektor gespeichert
    vector<Animal *> animals;

public:
    Zoo(string name, vector <Animal *> animals): _name(name), animals(animals){};
    Zoo()
    {
        // Name zuweisen
        cout << "Bitte Name des Zoos eingeben: ";
        cin >> _name;
        // Wenn der String kuerzer als 4 Zeichen ist,
        // dann MyException werfen
        // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
        if (_name.length() < 4){
          throw MyException(__FILE__, __LINE__ + 46, "Zooname zu kurz"); // Anpassung der Fehlermeldung an der Zeile
          }


        // Ansonsten, den 5. Buchstaben des Namens gross machen
        _name.at(4) = toupper(_name.at(4));
    }

    // Ein Tier dem Zoo hinzufuegen
    void add_animal(const Animal &animal)
    {
        // Wenn ein Elefant nach einer Maus eingefuegt wird, oder anders herum
        // dann Ausnahme werfen
        // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
        if (dynamic_cast<const Mouse*>(&animal) ) {
            for (auto existing : animals) {
                if (dynamic_cast<Elefant*>(existing)) {
                    // Anpassung der Fehlermeldung an der Zeile
                    throw ElefantMeetsMouse(__FILE__, __LINE__ + 48, "Maus trifft auf Elefant");
                }
            }
        }
        if (dynamic_cast<const Elefant*>(&animal)) {
            for (auto existing : animals) {
                if (dynamic_cast<Mouse*>(existing)) {
                    // Anpassung der Fehlermeldung an der Zeile
                    throw ElefantMeetsMouse(__FILE__, __LINE__ + 41, "Elefant trifft auf Maus");
                }
            }
        }

    // sonst Tier hinzufuegen
    animals.push_back(animal.clone());
	}
    // Alle Zootiere ausgeben
    void print() const {
      for (auto animal : animals){
              animal->print(true);
            }
        }

};

int main(int argc, char *argv[])
{
    char choice;
    string name;

    // Ausnahmepruefung aktivieren
    try{
        Zoo zoo;
        do
        {
            cout << endl
                 << "Bitte Tierart auswaehlen:" << endl;
            cout << "1 = Elefant" << endl;
            cout << "2 = Tiger" << endl;
            cout << "3 = Maus" << endl;
            cout << "e = Ende mit Eingabe" << endl;
            cout << "Eingabe: ";
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                Elefant elefant = Elefant();
                zoo.add_animal(elefant);
                break;
            }
            case '2':
            {
                Tiger tiger = Tiger();
                zoo.add_animal(tiger);
                break;
            }
            case '3':
            {
                Mouse mouse = Mouse();
                zoo.add_animal(mouse);
                break;
            }
            case 'e':
                break;
            default:
                // Einen String als Ausnahme werfen
                throw string("Fehlerhafte Eingabe!");

            }

            cout << endl;
            zoo.print();
        } while (choice != 'e');
    }
    // Ausnahmen auffangen
    // Speziellste Ausnahme auffangen und ausgeben
    catch (ElefantMeetsMouse &e)
    {
        cout << e.what()<< endl;
        return 1;
    }
    // MyException auffangen und ausgeben
    catch (MyException &e){
      cout << e.what() << endl;
    }


    // Alle anderen Standardausnahmen auffangen und ausgeben
    catch(exception &e){
        cout << "Standardausnahme: " << e.what() << endl;
      return 1;
    }


    // Alle Strings auffangen und ausgeben
    catch (const string &s){
      cout << s << endl;
      return 1;
    }


    // Alle anderen Ausnahmen auffangen
    catch(...){
      cout << "Unbekannte Ausnahme aufgetreten" << endl;
      return 1;
    }

    return 0;
}