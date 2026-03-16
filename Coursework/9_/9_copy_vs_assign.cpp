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
    {                                                   // simple copy constructor without swap (legacy version)
        std::cout << "assignment " << std::endl;
        number = c.number;
        return *this;
    }
};

int main() {
    std::cout << std::endl;

    Course{};                                           // def constructor
    Course c1{};                                        // def constructor
    Course c2{c1};                                      // copy constructor
    Course c3 = c1;                                     // copy constructor
    c1 = c2;                                            // assignment overload operator

    std::cout << std::endl;
    return 0;
}
