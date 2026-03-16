// S. Trowbridge 2023
#include <iostream>

class Vehicle {                            
protected:
    std::string brand;
public:
    Vehicle():brand("") {  std::cout << "V Ctr" << std::endl; }
};

class MotorVehicle: public Vehicle  {                                           // motorvehicle is-a vehicle
public:
    MotorVehicle():Vehicle() { std::cout << "MV Ctr" << std::endl; }
};

class Bike: public Vehicle {                                                    // bike is-a vehicle
public:                 
    Bike():Vehicle() {  std::cout << "B Ctr" << std::endl; }
};

// motorcycle is-a bike AND is a motorized vehicle AND is-a vehicle
//     V
//   /   \
//  MV    B
//   \   /
//     M
class Motorcycle : public MotorVehicle, public Bike {
public:
    Motorcycle(): Bike(), MotorVehicle() { std::cout << "M Ctr" << std::endl; }             
    void func(std::string b) { 
        //brand = b;                                                            // compiler error: do we assign brand from V\B or V\MV
        Bike::brand = b;                                                        // scope resolution: assign brand from Bike
    }
};

int main() {

    Motorcycle m;                                                                // two vehicle objects are instantiated, one for B, one for MV

    return 0;
}
