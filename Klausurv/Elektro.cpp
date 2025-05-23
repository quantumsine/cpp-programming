#include "Elektro.h"
#include <iostream>
using namespace std;

Elektro::Elektro(int id, int batterie): Fahrzeug(id), _batterie(batterie){}
void Elektro::print() const {
  Fahrzeug::print();
  cout << "Art: Elektro" << endl;
  cout << "Batterie: " << _batterie << "%" << endl;
}


