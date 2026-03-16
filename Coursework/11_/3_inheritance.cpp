// S. Trowbridge 2023
#include <iostream>

class Vehicle {                                                     // base class - Car is-a Vehicle
private:
    std::string brand;
public:
    Vehicle(): brand("") {}
    Vehicle(std::string b): brand(b) { std::cout << "V Ctor\n"; }
    std::string getBrand() const { return brand; }
};

class Car : public Vehicle {                                        // derived class - Car is-a Vehicle
public:
    Car(): Vehicle() {};                                            // derived constructor calls base constructor
    Car(std::string b): Vehicle(b) { std::cout << "C Ctor\n"; }     // derived constructor calls base constructor
};

int main() {
    std::cout << std::endl;

    Vehicle v("Acura");                                              // base constructor called
    std::cout << "v: " << v.getBrand() << "\n\n";                    // print base

    Car c("Lexus");                                                  // bass and derived constructors called
    std::cout << "c: " << c.getBrand() << "\n";                      // print derived using inherited function

    std::cout << std::endl;
    return 0;
}
