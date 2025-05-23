#include "Fuhrpark.h"
// #include "Verbrenner.h"
#include "Elektro.h"

void teste_fuhrpark(){
  Fuhrpark fuhrpark("Musterfirma");
  //Fahrzeug* verbrenner = new Verbrenner(1000, 80);
  Fahrzeug* elektro = new Elektro(1002, 100);
  //fuhrpark.fuege_hinzu(verbrenner);
  fuhrpark.fuege_hinzu(elektro);
  fuhrpark.buche_fahrzeug(elektro);
  fuhrpark.print();
  //fuhrpark.entferne_fahrzeug(verbrenner);

}

int main(){
  teste_fuhrpark();
  return 0;
}