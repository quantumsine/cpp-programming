
#include <string>
#include <iostream>
using namespace std;

// Klasse Student
class Student {
    private:
    string _name, _first_name;

    public:
    // Parametrisierter Konstruktor:
    Student(string name, string first_name) {
        _name = name;
        _first_name = first_name;
        cout << "Parametrisierter Konstruktor Student: " << first_name << " " << name << endl;
       
    }

    ~Student(){
        cout << "Destruktor Student: "<< _first_name << " " << _name << endl;
    }

    string get_name(){
        return _name;
    }
    string get_first_name(){
        return _first_name;
    }

    void print();
    void print(bool newline);

};


/*Aufgabenteil missverstanden: Print-Methoden sollten AUSSERHALB verwendet werden.
    Vorgehensweise: print-Methoden und klasse Student mit dem scope-resolution-Operator*/


void Student::print(){ // Zugriff auf die deklarierten Funktionen und den Namen
    cout << "print() ohne Parameter; Student: " << get_first_name() << " " << get_name() << endl;
}

void Student::print(bool newline){
    cout << "print() mit Parameter; Student: " << get_first_name() << " " << get_name();
    if(newline){
        cout << endl;
    }
}




// Klasse Employee
class Employee {
    private:
    string _name, _first_name;


    public:
    // Parametrisierter Konstruktor:
    Employee(string name, string first_name): _name(name), _first_name(first_name) {
        cout << "Parametrisierter Konstruktor Employee: " << first_name << " " << _name << endl;
    }
    
    // Standardkonstruktor: ruft parametrisierten Konstruktor auf:
    Employee(): Employee("Mustermann", "Erika") {
        cout << "Standardkonstruktor Employee: " << _first_name << " " << _name << endl;
    }

    // Konvertierungskonstruktor
    Employee(Student& stnt): _name(stnt.get_name()), _first_name(stnt.get_first_name()) {
        cout << "Konvertierungskonstruktor Employee: " << _first_name << " " << _name << endl;
    }

    ~Employee(){
        cout << "Destruktor Employee: "<< _first_name << " " << _name << endl;
    }

    void print(){
        cout << "print() ohne Parameter; Mitarbeiter: " << _first_name << " " << _name << endl;
    }

    void print(bool newline){
        cout << "print() mit Parameter; Mitarbeiter: " << _first_name << " " << _name;
        if(newline){
            cout << endl;
        }
        
    }
};


int main(int argc, char *argv[])
{
    Student stud_mustermann = Student("Mustermann", "Max");
    Employee empl_mustermann = Employee(stud_mustermann);
    Employee mit_default = Employee();
    stud_mustermann.print();
    stud_mustermann.print(true);
    empl_mustermann.print();
    mit_default.print();
    Student *p_stud_mustermann = nullptr;
    cout << "Block wird betreten" << endl;
    {
        p_stud_mustermann = new Student("Mustermann", "Markus");
        p_stud_mustermann->print(true);
    }
    cout << "Block wurde verlassen" << endl;
    delete p_stud_mustermann;
    return 0;
}

