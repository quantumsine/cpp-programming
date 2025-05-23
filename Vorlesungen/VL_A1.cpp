#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    private:
    int amount_axle;
    bool is_motorized;

    public:
        void set_amount_axle(int amount){
            amount_axle = amount;
        }

        int get_amount_axle(){
            return amount_axle;
        }

        void set_is_motorized(bool motorized){
            is_motorized = motorized;
        }


        void print_vehicle_info(){
            cout << "Anzahl der Achsen: " << amount_axle << endl;
            cout << "Motorisiert (1 = ja, 0 = nein): " << is_motorized << endl;
    
    }
};

int main(int argc, char const *argv[])
{
    Vehicle kutsche;
    kutsche.set_amount_axle(4);
    kutsche.set_is_motorized(false);
    kutsche.print_vehicle_info();

    Vehicle truck;
    truck.set_amount_axle(6);
    truck.set_is_motorized(true);
    truck.print_vehicle_info();
    return 0;
}
