// S. Trowbridge 2023
#include <iostream>

class Course {                              // create a complex variable type named Course        
public:          
    int number;                             // a Course object can contain multiple data members    
};

void print(Course &c) {                     // objects should be passed by reference  
    std::cout << c.number << std::endl;
}

int main() {
    std::cout << std::endl;

    Course c1;                              // instantiate (create) an object of type Course named c1
    Course c2;                              // instantiate (create) an object of type Course named c2

    // the dot operator can be used to read or write to Course object data members  
    c1.number = 580;                        // write to number inside object c1    
    c2.number = 574;                        // write to number inside object c2
          
    std::cout << c1.number << std::endl;    // read number from object c1      
    std::cout << c2.number << std::endl;    // read number from object c2

    // pass a Course object by reference to the print function
    print(c1);
    print(c2);

    std::cout << std::endl;
    return 0;
}
