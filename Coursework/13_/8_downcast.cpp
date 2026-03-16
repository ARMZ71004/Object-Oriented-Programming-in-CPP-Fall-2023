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
protected:
    int radius;
public:
    Circle(): Shape(), radius(1) {}
    Circle(int r): Shape(), radius(r) {}
    void print() const override { 
        std::cout << "Circle" << std::endl; 
    }
    float circumference() const {                               // unique function for type Circle
        return 2 * 3.14 * radius; 
    }      
};

int main() {
    std::cout << std::endl;

    Shape *s;
    Circle *c;

    s = new Circle{};
    //std::cout << ( s->circumference() ) << std::endl;         // shape pointer cannot call circumference : because a shape does not have a circumference (circle does)

    // c = s;                                                   // implicit downcast (compiler error)
    c = dynamic_cast<Circle*>(s);                               // explicit downcast (required) required to convert a shape pointer into a circle pointer
    std::cout << ( c->circumference() ) << "\n\n";              // circle pointer can call circumference


    /* data structure of base pointers to derived objects ******************************************/
    Shape **sp = new Shape*[4];
    sp[0] = new Shape{};
    sp[1] = new Circle{5};
    sp[2] = new Circle{12};  
    sp[3] = new Shape{};         

    for(int i=0; i<4; ++i) {
        if( Circle *cp = dynamic_cast<Circle*>( sp[i] ) ) {     // explicit downcast: if sp[i] is a circle, cp stores memory address, otherwise nullptr
            std::cout << ( cp->circumference() ) << std::endl;  
        } else {
            sp[i]->print();                                     
        }
    }

    std::cout << std::endl;
    return 0;
}

