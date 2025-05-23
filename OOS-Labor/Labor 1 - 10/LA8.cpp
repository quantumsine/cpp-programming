
#include <iostream>
using namespace std;

// Klasse Point und Circle implementieren
class Point{
    private:
    double _x;
    double _y;

    public:

    //Konstruktor mit defaultwerten
    Point(double x = 0, double y = 0) : _x(x), _y(y) {}

    ~Point(){
    }

    // Getter und Setter
    void set_x(double x){
        _x = x;
    }

    void set_y(double y){
        _y = y;
    }


    double get_x(){
        return _x;
    }

    double get_y(){
        return _y;
        }
    
    //Funktion, die die Koordinaten um dx und dy verschieben
    void move(double dx, double dy){
        _x += dx;
        _y += dy;
    }

    void print(bool newline = true){
        cout << "(" << _x << ", " << _y << ")";

        if (newline){
            cout << endl;
        }
    }

    
};



class Circle{
    private:
    Point _center;
    double _radius;

    public:
    Circle(Point center, double radius): _center(center), _radius(radius) {}
    
    Circle(Point center): _center(center), _radius(1) {} // Nach Aufgabenstellung: Wenn im Konstruktor kein Radius übergeben wird, ist der Radius 1

    ~Circle(){}

    void set_centre(Point center){
        _center = center;
        }
    
    void set_radius(double radius){
        _radius = radius;
    }

    Point get_center(){
        return _center;
    }

    double get_radius(){
        return _radius;
    }

    void move(double dx, double dy){
        _center.move(dx, dy);
        }

    void print(bool newline = true){
        cout << "[(" << _center.get_x() << ", " << _center.get_y() << "), " << _radius << "]";

        if (newline){
            cout << endl;
        }
    }



};

// Hauptprogramm
int main(int argc, char *argv[])
{
	Point p;
	Circle c(p);
	cout << "Ausgabe 1:" << endl;
	p.print();
	c.print();
	p.set_x(1.1);
	p.set_y(2.2);
	c.set_centre(p);
	c.set_radius(3.3);
	cout << "Ausgabe 2:" << endl;
	p.print(false);
	cout << " == (" << p.get_x() << ", " << p.get_y() << ")"<< endl;
	c.print();
	p.move(1.0, 1.0);
	c.move(2.0, 2.0);
	cout << "Ausgabe 3:" << endl;
	p.print();
	c.print();
	return 0;
}

