// S. Trowbridge 2023
#include <iostream>

class Shape {
public:
    Shape() = default;
    virtual void print() const { 
        std::cout << "Shape" << std::endl; 
    } 
};
class Circle: public Shape {  
public:
    void print() const override { 
        std::cout << "Circle" << std::endl; 
    }    
};

void f(Shape *s){ s->print(); }                 // implicit upcast - circle pointer converted to shape pointer when function is called

int main() {
    std::cout << std::endl;

    Shape *sp;
    Circle *cp;

    sp = new Circle{};                          // implicit upcast - convert a derived pointer into a base pointer
    sp->print();          

    cp = new Circle{};
    f(cp);                                      // implicit upcast  

    std::cout << std::endl;
    return 0;
}
