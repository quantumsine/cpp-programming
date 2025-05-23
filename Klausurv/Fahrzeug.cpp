#include <iostream>
#include <string>
#include <vector>
#include "Fahrzeug.h"
using namespace std;

Fahrzeug::Fahrzeug(int id): _id(id) {
  _anzahl++;
}

void Fahrzeug::buche(){
  _ist_gebucht = true;
}

bool Fahrzeug::ist_gebucht() const {
  return _ist_gebucht;
}

int Fahrzeug::get_id() const {
  return _id;
}

int Fahrzeug::get_anzahl() {
  return _anzahl;
}

bool Fahrzeug::operator==(const Fahrzeug &fahrzeug) const {
  return fahrzeug._id == _id;
}

void Fahrzeug::print() const {
  cout << "ID: " << _id << endl;
  cout << "Ist gebucht: " << _ist_gebucht << endl;

}

int Fahrzeug::_anzahl = 0;