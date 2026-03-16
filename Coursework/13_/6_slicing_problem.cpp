// S. Trowbridge 2023
#include <iostream>

class Shape {
protected:
    std::string name;
public:
    Shape() = default;
    Shape(std::string n): name(n) {}
    virtual ~Shape() {};      
    virtual void print() const { 
      std::cout << name << " Shape" << std::endl; 
    }      
};

class Sphere: public Shape {                        // Sphere is-a Shape
private:
    int diameter;
public:
    Sphere(std::string n, int d): Shape(n), diameter(d) {}
    void print() const override { 
      std::cout << name << " " << diameter << " Sphere" << std::endl; 
    }       
};

void f1(Shape a) { a.print(); }                     // derived object copied to base object: slicing 
void f2(Shape &a) { a.print(); }                    // base pointer to derived object : no slicing since copy does not occur
void f3(Shape *a) { a->print(); }                   // base reference to derived object : no slicing since copy does not occur

int main() {
    std::cout << std::endl;

    Shape s;
    Sphere b{ "Ball", 20 };

    s = b;                                          // derived object copied to base object : slicing
    s.print();

    Shape *sp = &b;                                 // base pointer to derived object : no slicing sincecopy does not occur
    sp->print();

    Shape &sr = b;                                  // base reference to derived object : no slicing since copy does not occur
    sr.print();

    std::cout << std::endl;

    f1(b); 
    f2(b); 
    f3(&b); 

    std::cout << std::endl;
    return 0;
}
