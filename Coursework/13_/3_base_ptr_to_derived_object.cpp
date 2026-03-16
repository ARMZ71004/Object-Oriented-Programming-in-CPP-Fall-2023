// S. Trowbridge 2023
#include <iostream>

class Shape {
protected:
    std::string name;
public:
    Shape() = default;
    Shape(std::string n): name(n) {}
    virtual void print() const { std::cout << name << " Shape" << std::endl; }      // virtual print function
};

class Circle: public Shape {                                                        // Circle is-a Shape
public:
    Circle(std::string n): Shape(n) {}
    void print() const override { std::cout << name << " Circle" << std::endl; }    // overridden print function   
};

class Square: public Shape {                                                        // Square is-a Shape
public:
    Square(std::string n): Shape(n) {}
    void print() const override{ std::cout << name << " Square" << std::endl; }     // overridden print function      
};

int main() {
    std::cout << std::endl;

    const int SIZE = 3;

    Shape *s = new Shape[SIZE];                                                     // array of shape objects  
    s[0] = Shape("Shape");  
    s[1] = Circle("Circle");
    s[2] = Square("Square");
    
    for(int i=0; i<SIZE; ++i) { s[i].print(); }

    std::cout << std::endl;

    Shape **sp = new Shape*[SIZE];                                                  // heterogeneous list of shape ptrs to subtype objects 
    sp[0] = new Shape("Shape");
    sp[1] = new Circle("Circle");
    sp[2] = new Square("Square");

    for(int i=0; i<SIZE; ++i) { sp[i]->print(); }

    std::cout << std::endl;
    return 0;
}
