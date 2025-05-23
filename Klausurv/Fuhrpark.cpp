#include "Fuhrpark.h"
#include "Fahrzeug.h"
#include <iostream>
#include <string>
#include <vector>

Fuhrpark::Fuhrpark(string name):_name(name){}

void Fuhrpark::fuege_hinzu(Fahrzeug* fahrzeug){
  bool existiert = false;
  for(size_t i = 0; i < _fahrzeuge.size(); i++){
    if(fahrzeug = _fahrzeuge[i]){
      existiert = true;
      }
    }

    if(existiert == false){
      _fahrzeuge.push_back(fahrzeug);
      _anzahl_fahrzeuge++;

      if(_anzahl_fahrzeuge == Fahrzeug::get_anzahl()){
        cout << "Alle existierenden Fahrzeuge wurden hinzugefügt" << endl;
      }
    }
  }

  void Fuhrpark::entferne_fahrzeug(Fahrzeug* fahrzeug){
    for(size_t i = 0; i < _fahrzeuge.size(); i++){
      if(fahrzeug == _fahrzeuge[i] && !_fahrzeuge[i]->ist_gebucht()){
        _fahrzeuge.erase(_fahrzeuge.begin() + i);
        _anzahl_fahrzeuge--;
      }
    }
  }
  void Fuhrpark::buche_fahrzeug(Fahrzeug* fahrzeug){
    for(size_t i = 0; i < _fahrzeuge.size(); i++){
      if(fahrzeug == _fahrzeuge[i]){
        _fahrzeuge[i]->buche();
      }
    }
  }

  void Fuhrpark::print() const{
    for(size_t i = 0; i < _fahrzeuge.size(); i++){
      _fahrzeuge[i]->print();
    }
  }