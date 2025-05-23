#ifndef ELEKTRO_H
#define ELEKTRO_H
#include "Fahrzeug.h"

class Elektro: public Fahrzeug{
  int _batterie;
  public:
    Elektro(int id, int batterie);
    void print() const override;
};

#endif //ELEKTRO_H
