// S. Trowbridge 2023
#include <iostream>

class Vehicle {                            
protected:
    std::string brand;
public:
    Vehicle():brand("") {  std::cout << "V Ctr" << std::endl; }
};

class MotorVehicle: public virtual Vehicle  {                                   // motorized vehicle is-a vehicle using virtual inheritance
public:
    MotorVehicle():Vehicle() { std::cout << "MV Ctr" << std::endl; }
};

class Bike: public virtual Vehicle {                                            // bike is-a vehicle using virtual inheritance
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
        brand = b;                                                              // ok, because only one vehicle object is created
    }
};

int main() {

    Motorcycle m;                                                               // one instead of two vehicle objects is created

    return 0;
}
