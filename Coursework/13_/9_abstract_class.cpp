// S. Trowbridge 2023
#include <iostream>

class Shape {                                                                       // abstract class
protected:
    std::string name;
public:
    // no constructors
    std::string getName() const { return name; }
    void setName(std::string n) { name = n; }
    virtual void print() const = 0;                                                 // pure virtual function
    virtual ~Shape() {}                                                             // virtual destructor
};

class Circle: public Shape {                                                        // Circle is-a Shape
public:
    void print() const override { std::cout << name << " Circle" << std::endl; }    
};

class Square: public Shape {                                                        // Square is-a Shape
public: 
    void print() const override{ std::cout << name << " Square" << std::endl; }         
};

int main() {
    std::cout << std::endl;

    //Shape s;                                                                      // compiler error: cannot instantiate an abstract class

    Shape *b1 = new Circle{};
    Shape *b2 = new Square{};
    b1->setName("Ring");
    b2->setName("Box");

    b1->print();
    b2->print();

    std::cout << std::endl;
    return 0;
}
