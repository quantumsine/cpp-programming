#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Fraction {
    int _nominator, _demnominator;

    public:
        /* 1. Konstruktur, auch der Standardkonstruktor
            Der Std-Konstruktor benutzt keine Parameter, Er heißt so, da er in Fällen benutzt wird
            wenn es keine Möglichkeit gibt, die anderen Konstruktoren zu benutzen. */
        Fraction(){
            _nominator = 0;
            _demnominator = 0;
        }

        /* 2. Konstruktor, der Kopierkonstruktor 
            Dieser hat 1 Parameter, um Objekte mit individuellen Werten zu initialisieren*/
        Fraction(int n){
            _nominator = n;
            _demnominator = 1;

        }

        Fraction(int n, int d){
            _nominator = n;
            _demnominator = d;
        }

        int get_nominator(){
            return _nominator;
        }

        int get_demnominator(){
            return _demnominator;
            }

    void print(){
        cout << _nominator << "/" << _demnominator << endl;
    }

};

    /* Die Initialisierung ist bis jetzt in 2 Schritten durchgeführt worden: 
            1. Beschaffung Speicherplatz für die Elemente
            2. Ausführung Programmcode & Zuweisung */

// Es geht auch in einem Schrit, zwar durch eine "member initializer list":

class Units{
    int _kilometers, _miles;
    public: 
    Units(int km, int mi) : _kilometers(km), _miles(mi){
        km = 50;
        cout << " kilometer" << km << endl;
        mi = km * 1.6;
        cout << "miles" << mi << endl;

    }
};


// 3. Der Konvertierkonstruktor, der einen anderen Typ/Klasse in den eigenen Typ/Klasse konvertiert
class Quotient{
    double result;
    public:
        Quotient(Fraction& f){
            result = (double)f.get_nominator() / (double)f.get_demnominator();
        }

        void print(){
            cout << result << endl;
        }
};

Temperature global_temperature;
int main(int argc, char const *argv[])
{
    Fraction f(2,3);
    f.print();
    Quotient q(f);
    q.print();
    return 0;


    cout << "Destruktoren" << endl;

    cout << "Main wird begonnen" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    Temperature a_temp(1);
    {
        cout << "Block wird begonnen" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        Temperature b_temp(2);
        cout << "Block wird beendet" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    cout << "Main wird beendet" << endl;
}


//4. Destruktor, er hat keine Parameter und kann nicht überladen werden
// Er wird aufgerufen, wenn delete oder die Gültigkeit eines Objekts endet

class Temperature{
    private:
        int _temperature;

    public: 
    Temperature(double t = 0.0) : _temperature(t){
        cout << "Objekt Temperatur erstellt " << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    ~Temperature(){
        cout << "Objekt Temperatur gelöscht" << endl;
        }
};