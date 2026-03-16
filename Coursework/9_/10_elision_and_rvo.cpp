// S. Trowbridge 2023
#include <iostream>

class Course {
private:
    int number;
public:
    Course(): number(0) 
    {
        std::cout << "def        " << std::endl;
    }
    Course(const Course &c): number(c.number) 
    {
        std::cout << "copy       " << std::endl;
    }
    Course& operator=(const Course &c) 
    {                                               // simple copy constructor without swap (legacy version)
        std::cout << "assignment " << std::endl;
        number = c.number;
        return *this;
    }
};

void passByValue(Course c) { }                      // accept an object via pass by value

Course returnByValue() {                            // return temporary by value
    Course c{};
    return c;
}

int main() {
    std::cout << std::endl;

    std::cout << "CONSTUCT OBJECTS:\n\n";

    Course c1{};                                    // call the default constructor
    Course c2 = c1;                                 // call the copy constructor
    Course c3 = Course{};                           // call the default constructor (optimized by copy elision)
    std::cout << "\n\n"; 

    std::cout << "PASS BY VALUE:\n\n";
    passByValue(c1);                                // call the copy constructor
    passByValue( Course{} );                        // call the default constructor (optimized by copy elision)
    std::cout << "\n\n"; 

    std::cout << "RETURN BY VALUE:\n\n";
    c3 = returnByValue();                           // call the default constructor, then assignment to copy returned temporary
    Course c4 = returnByValue();                    // call the default constructor (optimized by named return value optimization)

    std::cout << std::endl;
    return 0;
}
