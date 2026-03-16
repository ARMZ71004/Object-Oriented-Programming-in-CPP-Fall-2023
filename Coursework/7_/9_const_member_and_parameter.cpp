// S. Trowbridge 2023
#include <iostream>

class Course {                              
private:                                    
    int number;                                
public:
    Course():number(101) {                      
    }
    int getNumber() const {
        return number;
    }
};   

void print(const Course &c) {                   // c is a const parameter object: c cannot be modified by the print function
    std::cout << c.getNumber() << std::endl;    // this function compiles because getNumber is const member and cannot modify c
}

int main() {
    std::cout << std::endl;

    Course c1; 
    print(c1);

    std::cout << std::endl;
    return 0;
}
