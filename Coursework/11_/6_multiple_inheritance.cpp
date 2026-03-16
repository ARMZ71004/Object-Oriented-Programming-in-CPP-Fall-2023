// S. Trowbridge 2023
#include <iostream>

class Vehicle {
protected: 
    std::string brand;    
public:
    Vehicle():brand("") {  std::cout << "V Ctr" << std::endl; }
};

class Bike {
protected: 
    std::string brand;    
public:
    Bike():brand("") {  std::cout << "B Ctr" << std::endl; }
};

// V     B
//  \   /
//    M
class Motorcycle : public Vehicle, public Bike {        // motorcycle is-a vehicle and is-a bike
public:
    Motorcycle(): Bike(), Vehicle() { std::cout << "M Ctr" << std::endl; }  

    void func(std::string b) {
        //brand = b;                                    // compiler error: assign Bike brand or Vehicle brand?
        Vehicle::brand = b;                             // scope resolution specifies assign brand from Vehicle
    }
    
};

int main() {
    Motorcycle m;
    return 0;
}
