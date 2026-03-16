// S. Trowbridge 2023
#include <iostream>

class Course {                              
public:                                     
    int number;                                 // data member
    
    int getNumber() {                           // member function: declared inside the class
        return number; 
    }
};   

void print(Course &c) {                         // non-member function: declared outside of the class
    std::cout << c.number << std::endl; 
}

int main() {
    std::cout << std::endl;

    Course c1;                                  // instantiate (create) an object of type Course named c1

    c1.number = 580;                            // assign a c1 data member

    std::cout << c1.number << std::endl;        // read a c1 data member
    std::cout << c1.getNumber() << std::endl;   // read a c1 data member using a member function 

    print(c1);                                  // access c1 data using a non-member function

    std::cout << std::endl;
    return 0;
}
