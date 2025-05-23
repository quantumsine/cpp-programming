#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Fahrzeug{
  public:
    virtual void beschleunige(){
      cout << "Fahrzeug beschleunigt..." << endl;
      }
   virtual ~Fahrzeug(){
   }
};


class Auto: public Fahrzeug{
  public:
    void beschleunige() override {
      cout << "Auto beschleunigt auf 100 km/h!" << endl;
    }
};

class Motorrad: public Fahrzeug{
  public:
    void beschleunige() override {
      cout << "Motorrad beschleunigt schnell auf 150 km/h!" << endl;
    }
};

void test_fahrzeug(Fahrzeug* f){
  f->beschleunige();
}



int main() {
  vector<Fahrzeug*> fahrzeuge;

  fahrzeuge.push_back(new Auto());
  fahrzeuge.push_back(new Motorrad());
  fahrzeuge.push_back(new Motorrad());
  fahrzeuge.push_back(new Auto());

  for (Fahrzeug* f : fahrzeuge) {
    test_fahrzeug(f);
  }

  for (Fahrzeug* f : fahrzeuge) {
    delete f;
  }

  return 0;
}