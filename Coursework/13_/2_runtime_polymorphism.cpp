// S. Trowbridge 2023
#include <iostream>

class Shape {
public:
    void print() const { std::cout << "Shape\n"; };                // non-virtual function (early / static binding)
    virtual void printV() const { std::cout << "Shape\n"; };       // virtual function (late / dynamic binding)
};

class Circle: public Shape {
public:
    void print() const { std::cout << "Circle\n"; };               // redefined function
    void printV() const override { std::cout << "Circle\n"; };     // redefined virtual function (overridden) 
};

int main() {
    std::cout << std::endl;

    Circle c{};

    Shape &sr = c;      
    Shape *sp = &c;    
    Circle &cr = c;       
    Circle *cp = &c;      

    std::cout << "NON VIRTUAL FUNCTION: " << "\n";                  // pointer or reference decides which version of function to run (early / static binding)
    c.print();                                                      
    sr.print();       
    sp->print(); 
    cr.print();     
    cp->print();   

    std::cout << "\nVIRTUAL FUNCTION: " << "\n";                    // object decides which version of function to run (late / dynamic binding)
    c.printV();                                                  
    sr.printV();       
    sp->printV(); 
    cr.printV();     
    cp->printV();   

    std::cout << std::endl;
    return 0;
}
