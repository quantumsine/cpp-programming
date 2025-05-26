#include <iostream>
#include <string>

class Car {
    std::string brand;
    int production_year;
    double fuel_in_liters;
    double usage_per_100km;

public:
    Car(const std::string& brand, int production_year, double fuel_in_liters, double usage_100km): brand(brand), production_year(production_year), fuel_in_liters(fuel_in_liters), usage_per_100km(usage_100km) {}

    virtual ~Car() = default;

    std::string getBrand() const {
        return brand;
    }

    int getProductionYear() const{
        return production_year;
    }

    virtual void drive(double km) {
        double usage = (km / 100) * usage_per_100km;
        if (usage > fuel_in_liters) {
            throw std::runtime_error("Not enough fuel!");
        }
        fuel_in_liters -= usage;
        std::cout << brand << " drives " << km << " km and uses " <<  usage_per_100km << " liter." << std::endl;
    }

    void fuel(double liter) {
        if (fuel_in_liters  + liter > 60) {
            throw std::runtime_error("Too much fuel -> A max of only 60 liters is permitted!");
        }
        fuel_in_liters += liter;
        std::cout << brand << "refuels " << liter << " liters." << std::endl;
    }
};

class ElectricCar : public Car {
    double batteryCapacity_kWh;
    double usage_100km;

    public:
    ElectricCar(const std::string& brand, int year, double batterCapacity, double usage): Car(brand, year, 0, 0), batteryCapacity_kWh(batterCapacity), usage_100km(usage) {}

    ~ElectricCar() override = default;
    void drive(double km) override {
        double needed = (km / 100) * usage_100km;
        if (needed > usage_100km) {
            throw std::runtime_error("Not enough reach!\n");
        }
        batteryCapacity_kWh -= km;
    }

    void charge(double kWh) const {
        if (batteryCapacity_kWh + kWh > 100) {
            throw std::runtime_error("Maximum permitted capacity is 100 kWh!\n");
        }
    }
};

// Exception-Klassen
class FuelOverflowException: public std::exception {
    public:
    const char* what() const  noexcept override {
        return "Fuel overflow: only a max of 60 liters is possible\n";
    }
};

class BatteryOverflowException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Battery overflow: only a max of 100kWh is possible\n";
    }

};

class ReachException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "The electric car may not have enough reach\n";
    }

};



int main() {
    try {
        Car* car = new Car("Audi A4", 2021, 20, 7.0);
        car->drive(250.0);
        car->fuel(30);
        car->fuel(40); // exception here

        ElectricCar* ecar = new ElectricCar("Polestar", 2023, 80, 20);
        ecar->drive(250.0);
        ecar->charge(20.0);
        ecar->drive (200);

        delete car;
        delete ecar;
    }
    catch (FuelOverflowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (BatteryOverflowException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (ReachException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    }


    return 0;
}