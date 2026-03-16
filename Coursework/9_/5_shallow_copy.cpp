// S. Trowbridge 2023
#include <iostream>

class Course {
private:
    int *number;                            // dynamic data member
public:
    Course(): Course(0) {} 
    Course(int n): number(new int(n)) {}     // initialize dynamic memory
    void shallowCopy(const Course &c);
};

void Course::shallowCopy(const Course &c) 
{                                           // shallow copy: copy variable value
    std::cout << number << "\n";            
    std::cout << c.number << "\n";          
    std::cout << *number << "\n";           
    std::cout << *(c.number) << "\n\n";     

    number = c.number;                      // copy memory addresses

    std::cout << number << "\n";            // object memory ownership corrupted (both objects now share memory)
    std::cout << c.number << "\n";
    std::cout << *number << "\n";
    std::cout << *(c.number) << "\n";
}

int main() 
{
    std::cout << std::endl;

    Course c1{580};
    Course c2{575};

    c1.shallowCopy(c2);

    std::cout << std::endl;
    return 0;
}
