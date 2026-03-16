// S. Trowbridge 2023
#include <iostream>

class Course {
public:
    int number;                                 // public data member
    Course(): Course(0) {}        
    Course(int n): number(n) {} 
    int getNumber() const 
    { 
        return number;
    }
};

int main() 
{
    std::cout << std::endl;

    Course *c = new Course{};                   // dynamic object

    (*c).number = 580;                          // dereference pointer to access object data
    std::cout << (*c).getNumber() << "\n";      // dereference pointer to access object functions

    c->number = 585;                            // dereference pointer to access object data
    std::cout << c->getNumber() << "\n\n";      // dereference pointer to access object functions

    std::cout << std::endl;
    return 0;
}
