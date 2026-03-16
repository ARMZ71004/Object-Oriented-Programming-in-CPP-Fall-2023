// S. Trowbridge 2023
#include <iostream>

struct Course {                 // create a complex variable type named Course                  
    int number;                 // a Course can contain multiple variables
    std::string name;       
};

void print(Course &c) {         // this function accepts a Course variable by reference   
    std::cout << c.number << " " << c.name << std::endl;
}

int main() {
    std::cout << std::endl;

    Course c1;                  // create a variable of type Course named c1
    Course c2;                  // create a variable of type Course named c2


    // the dot operator can be used to read or write to Course variable data
    c1.number = 580;            // write to number inside variable c1    
    c1.name = "OOP in C++";     // write to name inside variable c1
    c2.number = 574;            // write to number inside variable c2  
    c2.name = "Python";         // write to name inside variable c2

    std::cout << c1.number << " " << c1.name << std::endl;             
    std::cout << c2.number << " " << c2.name << std::endl;  

    // pass a Course variable by reference to the print function
    print(c1);
    print(c2);

    std::cout << std::endl;
    return 0;
}
