// S. Trowbridge 2023
#include <iostream>

class Course {                              
private:                                                                
    int number; 
    int enrollment;                                
public:                                         
    Course():number(101), enrollment(0) {              // default constructor                         
    }       
    Course(int n):number(n), enrollment(0) {           // user defined constructor
    }
    Course(int n, int e):number(n), enrollment(e) {    // user defined constructor
    }

    void print() {                              
        std::cout << number << " " << enrollment << std::endl;
    }
}; 

int main() {
    std::cout << std::endl;

    Course c1;                                         // call the default constructor
    Course c2(580);                                    // call the one-parameter constructor
    Course c3(574, 30);                                // call the two-parameter constructor

    c1.print();
    c2.print();
    c3.print();

    std::cout << std::endl;
    return 0;
}
