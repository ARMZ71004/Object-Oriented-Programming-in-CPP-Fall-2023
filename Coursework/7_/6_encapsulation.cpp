// S. Trowbridge 2023
#include <iostream>

class Course {                              
private:                                        // private access modified: private members are only accessible by member functions                         
    int number;                                 
public:                                         // public access modifier: public members are accessible by any function
    Course() {                                  // constructor                         
        number = 101;
    }
    void setNumber(int n) {                     // mutator
        number = n;
    }      
    int getNumber() {                           // accessor
        return number; 
    }          
}; 

int main() {
    std::cout << std::endl;

    Course c1;                                  // constructor is public   

    c1.setNumber(580);                          // setNumber is public
    std::cout << c1.getNumber() << std::endl;   // getNumber is public

    //c1.number = 574;                          // compiler error: number is private

    std::cout << std::endl;
    return 0;
}
