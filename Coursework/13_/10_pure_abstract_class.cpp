// S. Trowbridge 2023
#include <iostream>

class Shape {                                                               // pure abstract class (interface)
protected:
    Shape() = default;                                                      // hide the default constructor
    Shape(const Shape &rhs) = default;                                      // hide the copy constructor
    Shape& operator=(const Shape &rhs) = default;                           // hide the assignment overload
    Shape(Shape &&rhs) = default;                                           // hide the move constructor
    Shape& operator=(Shape &&rhs) = default;                                // hide the move assignment overload
public:                                                                            
    virtual void print() const = 0;                                         
    virtual int getNumSides() const = 0;                                    
    virtual Shape* create() const = 0;                                      // virtual constructor idiom - simulate a constructor for derived classes
    virtual Shape* clone() const = 0;                                       // virtual constructor idiom - simulate a copy constructor for derived classes  
    virtual ~Shape() {}                                                     // virtual destructor
};

class Circle: public Shape {                                                // circle is-a shape
private:
    int *numSides;
public:
    Circle(): numSides( new int{0} ) {} 
    int getNumSides() const override { return *numSides; }
    void print() const override { 
        std::cout << "Circle: " << *numSides << " sides" << std::endl; 
    }   
    virtual Circle* create() const override { return new Circle{}; };       // covariant override - call the default constructor
    virtual Circle* clone() const override { return new Circle{*this}; };   // covariant override - call the copy constructor

    Circle(const Circle &rhs):                                              // the big five
        Shape(rhs), 
        numSides( new int( *(rhs.numSides) ) ) {
    }   
    Circle& operator=(const Circle &rhs) {
        Shape::operator=(rhs);
        Circle tmp(rhs);
        swap(*this, tmp);
        return *this;
    }
    Circle(Circle &&rhs) noexcept = default;
    Circle& operator=(Circle &&rhs) noexcept = default;
    friend void swap(Circle &obj, Circle &tmp) noexcept {
        using std::swap;
        swap(obj.numSides, tmp.numSides);
    }
    ~Circle() { delete numSides; }     
};

class Square: public Shape {                                                // square is-a shape
private:
    int *numSides;
public: 
    Square(): numSides( new int{4} ) {}
    virtual Square* create() const override{ return new Square{}; };        // covariant override - call the default constructor
    virtual Square* clone() const override{ return new Square{*this}; };    // covariant override - call the copy constructor
    int getNumSides() const override { return *numSides; }        
    void print() const override{ 
        std::cout << "Square: " << *numSides << " sides" << std::endl; 
    }     

    Square(const Square &rhs):                                              // the big five    
        Shape(rhs), 
        numSides( new int( *(rhs.numSides) ) ) {
    }
    Square& operator=(const Square &rhs) {
        Shape::operator=(rhs);
        Square tmp(rhs);
        swap(*this, tmp);
        return *this;
    }
    Square(Square &&rhs) = default;
    Square& operator=(Square &&rhs) = default;
    friend void swap(Square &obj, Square &tmp) {
        using std::swap;
        swap(obj.numSides, tmp.numSides);
    }
    ~Square() { delete numSides; }        
};

class Item {
private:
    Shape *s;                                                               // Shape could point to a Circle or a Square
public:
    Item(Shape *shp): s(shp) {}

    Item(const Item &rhs): s( rhs.s->clone() ) {}                           // the big five - clone will call the shape subtype copy constructor
    Item& operator=(const Item &rhs) {
        Item tmp(rhs);
        swap(*this, tmp);
        return *this;
    }
    Item(Item &&rhs) = default;
    Item& operator=(Item &&rhs) = default;
    friend void swap(Item &obj, Item &tmp) {
        using std::swap;
        swap(obj.s, tmp.s);
    }
    ~Item() { delete s; }

    void print() const { s->print(); }
};

int main() {
    std::cout << std::endl;

    Shape **s = new Shape*[3];                                              // heterogeneous list
    s[0] = new Circle{};
    s[1] = new Square{};
    s[2] = new Square{};      
 
    Item i1{s[0]};                                                          // create an item that stores a circle
    Item i2{s[1]};                                                          // create an item that stores a square

    i1.print();                                                                    
    i2.print();    

    std::cout << std::endl;
    return 0;
}
