// S. Trowbridge 2023
#include <iostream>

class Course {
private:
    int *number;                            // dynamic data member
public:
    Course(): Course(0) {}
    Course(int n): number(new int(n)) {}    // initialize dynamic memory
    void deepCopy(const Course &c);
};

void Course::deepCopy(const Course &c) 
{                                           // deep copy: deference, then copy the value
    std::cout << number << "\n";            
    std::cout << c.number << "\n";          
    std::cout << *number << "\n";           
    std::cout << *(c.number) << "\n\n";     

    *number = *(c.number);                  // copy data

    std::cout << number << "\n";            // object memory ownership is maintained
    std::cout << c.number << "\n";
    std::cout << *number << "\n";
    std::cout << *(c.number) << "\n";
}

int main() 
{
    std::cout << std::endl;

    Course c1{580};
    Course c2{575};

    c1.deepCopy(c2);

    std::cout << std::endl;
    return 0;
}
