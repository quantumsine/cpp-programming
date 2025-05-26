#include <iostream>


class Base{
    public:
    
    Base(){
        std::cout << "Base constructor called" << std::endl;
    }

    ~Base(){
        std::cout << "Base destructor called" << std::endl;
    }


};


class Derived : public Base{
    public:

    int i = 4;

    Derived(){
        std::cout << "Derived constructor called" << std::endl;
    }

    ~Derived(){
        std::cout << "Derived destructor called" << std::endl;
    }

    void print(){
        std::cout << "i = " << i << std::endl;
    }
};


int main () {
    Derived d;
    d.Derived::print();
    return 0;
}