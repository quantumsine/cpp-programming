#ifndef FUHRPARK_H
#define FUHRPARK_H
#include "Fahrzeug.h"
#include <string>
#include <vector>
using namespace std;

class Fuhrpark{
  int _anzahl_fahrzeuge;
  string _name;
  vector<Fahrzeug*>_fahrzeuge;

  public:
    Fuhrpark(string name);
    void fuege_hinzu(Fahrzeug* fahrzeug);
    void entferne_fahrzeug(Fahrzeug* fahrzeug);
    void buche_fahrzeug(Fahrzeug* fahrzeug);
    void print() const;
};
#endif //FUHRPARK_H
