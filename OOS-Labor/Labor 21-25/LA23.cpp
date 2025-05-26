#include <iostream>
#include <vector>
using namespace std;

class IComponent{
  public:
    virtual int get_price() = 0;
    virtual void add(IComponent* component) = 0;
    // virtual ~IComponent(){}
};


class Product: public IComponent{
    int price;

public:
  Product(int price) : price(price){}
  int get_price() override {
    return price;
  }

  // Preisaddition, wenn ein neues Produkt hinzugefügt wird
  void add(IComponent* component) override {
    price += component->get_price();
  }
};

// Inhalt anderer Boxen oder Produkte
class Box: public IComponent{
  vector<IComponent*> components;
  public:
    // Hinzufügen der inneren Boxen/Produkte
    void add(IComponent* component) override {
      components.push_back(component);
    }
    // summe der Produkte (in der Box) werden berechnet
    int get_price() override {
      int sum = 0;
      for (auto c: components){
        sum += c->get_price();
      }
      return sum;
    }
};


// Preisausgabe nach Eingabe des Produktes
void calculate_price(IComponent *component)
{
    cout << "Preis: " << component->get_price() << endl;
}

// Darstellung main:
/* Outer Box
    -> Inner Box 1: product 1 (10) + Product 2 (5)
    -> Dann: Inner Box 2: product 3 (4) + product 4 (7)
*/

int main(int argc, char* argv[]) {

    cout << "Preisermittlung für ein einfaches Produkt: " << endl;
    IComponent *product = new Product(10);
    calculate_price(product);
    cout << endl;

    cout << "Preisermittlung für eine verschachtelte Box: " << endl;
    IComponent *outer_box = new Box;
    IComponent *inner_box_1 = new Box;
    IComponent *product_1 = new Product(10);
    IComponent *product_2 = new Product(5);
    IComponent *product_3 = new Product(4);
    inner_box_1->add(product_1);
    inner_box_1->add(product_2);
    IComponent *inner_box_2 = new Box;
    inner_box_2->add(product_3);
    outer_box->add(inner_box_1);
    outer_box->add(inner_box_2);
    calculate_price(outer_box);
    cout << endl;

    cout << "Preisermittlung für eine erweiterte verschachtelte Box: " << endl;
    IComponent *product_4 = new Product(7);
    inner_box_2->add(product_4);
    calculate_price(outer_box);
    cout << endl;

    return 0;
}

