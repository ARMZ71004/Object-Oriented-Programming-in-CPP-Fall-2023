// S. Trowbridge 2023
#include <iostream>

class Vehicle {
private:
    std::string brand;                                  // data to be inherited
public:
    Vehicle(): brand("") {}
    Vehicle(std::string b): brand(b) { std::cout << "V Ctor\n"; }

    std::string getBrand() const { return brand; }      // function to be inherited
};

class Car : public Vehicle {                            // car is-a vehicle
private:
    int numDoors;                                       // data unique to Car
public:
    Car(): Vehicle(), numDoors(0) {};
    Car(std::string b, int n): Vehicle(b), numDoors(n) { std::cout << "C Ctor\n"; }

    int getNumDoors() const { return numDoors; }        // function unique to Car
};

class Boat : public Vehicle {                           // boat is-a vehicle
private:
    int hullLength;                                     // data unique to Boat
public:
    Boat(): Vehicle(), hullLength(0) {};
    Boat(std::string b, int l): Vehicle(b), hullLength(l) { std::cout << "B Ctor\n"; }
    
    int getHullLength() const { return hullLength; }    // function unique to Boat
};

int main() {
    std::cout << std::endl;

    Vehicle v("Acura");
    std::cout << "v: " << v.getBrand() << "\n\n";

    Car c("Lexus",2);
    std::cout << "c: " << c.getBrand() << " " << c.getNumDoors() << " door" << "\n\n";

    Boat b("Baja",45);
    std::cout << "b: " << b.getBrand() << " " << b.getHullLength() << "ft" << "\n";

    std::cout << std::endl;
    return 0;
}
