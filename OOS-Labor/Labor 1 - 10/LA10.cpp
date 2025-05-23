
#include <string>
#include <iostream>
using namespace std;

class Person {
protected: // Damit die ableiteten Klassen Zugriff auf die Daten haben
// (Alternativ könnte es man mit konstanter Methode string get_name() const{} lösen
	string _name; 
	int _check_out_duration;
public:
	Person(string name, int check_out_duration = 0);
	int get_check_out_duration() const;
	void print() const;
    string get_name() const;
};

// Implmentierung des Konstruktors und der Methoden
Person::Person(string name, int check_out_duration): _name(name), _check_out_duration(check_out_duration) {}



int Person::get_check_out_duration() const{
    return _check_out_duration;
}

void Person::print() const{
    // Ausgabe schon in der main-Funktion enthalten, aber für den Zugriff von ableitenden Klassen wird sie deklariert - tut aber nichts
}

// Alternative Implementierung von _name
/*string Person::get_name() const{
    return _name;
} 
*/

class Lecturer: public Person {

	int _examiner_id;
public:
	Lecturer(string name, int examiner_id);
	void print() const;
};

// Implmentierung des Konstruktors und der Methoden
Lecturer::Lecturer(string name, int examiner_id): Person(name, 90), _examiner_id(examiner_id) {}

void Lecturer::print() const{
    cout << _name << ", Prüfernummer " << _examiner_id << endl;
    Person::print();
}



class Student: public Person {

	int _matriculation_number;

public:
	Student(string name, int matriculation_number);
	void print() const;
};

// Implmentierung des Konstruktors und der Methoden
Student::Student(string name, int matriculation_number): Person(name, 30), _matriculation_number(matriculation_number) {}

void Student::print() const{
    cout << _name << ", Matrikelnummer " << _matriculation_number << endl;
    Person::print();
}


int main(int argc, char *argv[]) {
    Student smith = Student("smith", 12345678);
    Lecturer miller = Lecturer("miller", 98);
    smith.print();
    cout << "Ausleihdauer: " << smith.get_check_out_duration() << " Tage(e)" << endl;
    miller.print();
    cout << "Ausleihdauer: " << miller.get_check_out_duration() << " Tage(e)" << endl;
}

