// S. Trowbridge 2023
#include <iostream>

class Vehicle { 
protected:
    std::string brand;
public:
    Vehicle(std::string b): brand(b) {}
    void print() { std::cout << brand <<  "\n"; }                   // base print function
};

class Car : public Vehicle { 
private:
    std::string model;
public:
    Car(std::string b, std::string m): Vehicle(b), model(m) {}  
    void print() {                                                  // redefined print function  
        std::cout << brand << " " << model <<  "\n"; 
    }
    void print(std::string s) {                                     // overloaded print function   
        std::cout << s << " " << brand << " " << model <<  "\n"; 
    }
};

int main() {
    std::cout << std::endl;

    Car c("Lexus", "GX300");

    c.Vehicle::print();                                             // base function (scope resolution required to call base version)
    c.print();                                                      // redefined function
    c.print("Tom's");                                               // overloaded function

    std::cout << std::endl;
    return 0;
}
