// S. Trowbridge 2023
#include <iostream>

class Shape {
public:
    ~Shape() {std::cout << "Shape Dtor" << std::endl; }
};
class Circle: public Shape {                                       // Circle is-a Shape
public:
    ~Circle() {std::cout << "Circle Dtor" << std::endl; }
};


class Symbol {
public:
    virtual ~Symbol() {std::cout << "Symbol Dtor" << std::endl; }   // destructor is virtual
};
class Letter: public Symbol {                                       // Letter is-a Symbol
public:
    ~Letter() {std::cout << "Letter Dtor" << std::endl; }
};

int main() {
    std::cout << std::endl;

    std::cout << "NON VIRTUAL DESTRUCTOR: " << "\n";
    Shape *Shape = new Circle{};                                    // base destructor called  
    delete Shape;

    std::cout << "\nVIRTUAL DESTRUCTOR: " << "\n";                  
    Symbol *Symbol = new Letter{};                                  // base and derived destructor called (due to virutal destructor)
    delete Symbol;  

    std::cout << std::endl;
    return 0;
}
