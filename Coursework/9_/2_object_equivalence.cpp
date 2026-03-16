// S. Trowbridge 2023
#include <iostream>

class Course {
private:
    int number;
public:
    Course(): Course(0) {}
    Course(int n): number(n) {}       
    bool operator ==(const Course& c) const 
    { 
        return number == c.number; 
    }
};

int main() 
{
    std::cout << std::endl;

    Course c1{580};                         // automatic objects
    Course c2{580};                         // automatic objects

    std::cout << (&c1 == &c2) << "\n";      // check if same object (compare memory address)
    std::cout << (c1 == c2) << "\n\n";      // check if an equivalent object (compare object, requires == overload)
    

    Course *c3 = new Course{575};           // dynamic objects
    Course *c4 = new Course{580};           // dynamic objects
    Course *c5 = c4;

    std::cout << c3 << "\n";                // print pointer value
    std::cout << c4 << "\n";                // print pointer value
    std::cout << c5 << "\n\n";              // print pointer value

    std::cout << (c3 == c4) << "\n";        // check if same object (compare memory address)
    std::cout << (c4 == c5) << "\n\n";      // check if same object (compare memory address)

    std::cout << (*c3 == *c4) << "\n";      // check if an equivalent object (compare object, requires == overload)
    std::cout << (*c4 == *c5) << "\n\n";    // check if an equivalent object (compare object, requires == overload)

    std::cout << std::endl;
    return 0;
}
