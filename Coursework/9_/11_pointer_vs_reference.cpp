// S. Trowbridge 2023
#include <iostream>

class Course {
public:
    int number;                     // public data member
    Course(): Course(0) {}
    Course(int n): number(n) {}
};

void output(Course *x) 
{                                   // pass object by pointer (increased chance of memory errors)
    std::cout << x->number << "\n"; 
} 
void output(Course &x) 
{                                   // pass object by reference
    std::cout << x.number << "\n"; 
}  

int main() {
    std::cout << std::endl;

    Course *c1 = new Course{};      // dynamic object
    output(c1);                     // pass dynamic object by pointer
    output(*c1);                    // pass dynamic object by reference

    Course c2;                      // automatic object
    output(&c2);                    // pass automatic object by pointer
    output(c2);                     // pass automatic object by reference

    std::cout << std::endl;
    return 0;
}
