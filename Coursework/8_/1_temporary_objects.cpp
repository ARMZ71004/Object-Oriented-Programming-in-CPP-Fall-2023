// S. Trowbridge 2023
#include <iostream>

class Course {
private:
    int number;
public:
    Course(): number(20) {}
    Course(int n): number(n) {}
    int getNumber() const { return number; }
};


Course f1() {                                  
    Course c{5};                     
    return c;                                   // o goes out of scope, temporary object (copy of c) is returned
}

int main() {
    std::cout << std::endl;

    Course();                                   // instantiate a temporary object which immediately goes out of scope 

    f1();                                       // return by value, returns a temporary object which immediately goes out of scope

    Course c1 = f1();                           // c1 is copied from a temporary object which immediately goes out of scope

    std::cout << c1.getNumber() << std::endl;

    std::cout << std::endl;
    return 0;
}
