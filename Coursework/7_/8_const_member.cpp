// S. Trowbridge 2023
#include <iostream>

class Course {                              
private:                                  
    int number;                                
public: 
    Course():number(101) {                      
    }
    void setNumber(int n) {                     
        number = n;
    }      
    int getNumber() const {                     // const-member function: a function that does not modify the calling object
        return number; 
    }       
    void print() const {                        // const-member function: a function that does not modify the calling object
        std::cout << number << std::endl;
    }   
};   

int main() {
    std::cout << std::endl;

    Course c1;                                  // c1 is the calling object for the constructor, c1 is modified by this function

    c1.setNumber(580);                          // c1 is the calling object for the mutator, c1 is modified by this function

    std::cout << c1.getNumber() << std::endl;   // c1 is the calling object for the accessor, c1 is NOT modified by this function  

    c1.print();                                 // c1 is the calling object for this function, c1 is NOT modified by this function

    std::cout << std::endl;
    return 0;
}
