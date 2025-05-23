#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

class Meal {
public:
    string _name;
    Meal(string name) : _name(name) {}
    virtual void prepare(){
      cout << "Hefeteig machen" << endl;
      cout << "Kneten..." << endl;
    }

    virtual void add_topping(string topping) = 0;
};

class Pizza : public Meal {
  vector<string> _topping;
public:
  Pizza(string name) : Meal(name){}

  void add_topping(string topping) override{
    _topping.push_back(topping);
  }
  void prepare() override {
    cout << "Pizza " <<_name << ". Pizzaboden, belegt mit:"  << endl;

    for (auto& t : _topping){
      cout << "- " << t << endl;
    }
  }
};

  class Burger: public Meal {
    vector<string> _topping;
  public:
    Burger(string name): Meal(name) {}

    void add_topping(string topping) override{
      _topping.push_back(topping);
    }
    void prepare() override {
      cout <<_name<< ". Brötchen mit:"  << endl;
      for (auto& t : _topping){
        cout << "- " << t << endl;
      }
    }
  };

int main(int argc, char* argv[]) {
  Pizza *mista = new Pizza("Mista");
  mista->add_topping("Salami");
  mista->add_topping("Pilzen");
  Meal *hawaii = new Pizza("Hawaii");
  hawaii->add_topping("Schinken");
  hawaii->add_topping("Ananas");
  Burger *hamburger = new Burger("Hamburger");
  hamburger->add_topping("Hackfleisch");
  Meal *cheesburger = new Burger("Cheesburger");
  cheesburger->add_topping("Hackfleisch");
  cheesburger->add_topping("Käse");
  array<Meal *, 4> menu = {mista, hawaii, hamburger, cheesburger};
  for (Meal *g : menu)
  {
    g->prepare(); //*[1]
  }

  return 0;
}
