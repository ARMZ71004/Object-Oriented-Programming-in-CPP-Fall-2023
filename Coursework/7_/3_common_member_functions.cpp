// S. Trowbridge 2023
#include <iostream>

class Course {                              
public:                                     
    int number;                                 // data member

    Course():number(101) {                      // constructor: initialize object data members
    }
    void setNumber(int n) {                     // mutator: assign object data members
        number = n;
    }      
    int getNumber() {                           // accessor: reads object data members
        return number; 
    }          
};   

int main() {
    std::cout << std::endl;

    Course c1;                                  // allocate c1, initialize with the constructor
    std::cout << c1.getNumber() << std::endl;   // read with an accessor

    c1.setNumber(580);                          // assign with a mutator
    std::cout << c1.getNumber() << std::endl;   // read with an accessor

    std::cout << std::endl;
    return 0;
}
