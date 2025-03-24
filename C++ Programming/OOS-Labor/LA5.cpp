
#include<iostream>
using namespace std;

// hier die Klasse Punkt implementieren
class Point{
    public:
    double x, y; //Die Datenelemente 


    // this: Pointer der auf das veränderte Objekt x (unten y) zeigt
    // hilft dabei, die variablen von den Elementen zu unterscheiden
    void set_x(double x){
        this->x = x; 
    }
    void set_y(double y){
        this->y = y;
    }


    double get_x(){
        return x;
        }
    
    double get_y(){
        return y;
        }

    void print(){
        cout << "print-Methode:" << endl;
        cout << "X = "<< x << endl;
        cout << "Y = "<< y << endl;
    }
};

int main(int argc, char* argv[]) {
    Point p;
    p.set_x(1);
    p.set_y(10.5);
    p.print();
    p.set_x(5);
    cout << "X ohne print(): " << p.get_x() << endl;
    cout << "Y ohne print(): " << p.get_y() << endl;
    return 0;
}

