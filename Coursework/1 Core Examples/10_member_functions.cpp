// S. Trowbridge 2023
#include <iostream>

struct Course {                                             // create a complex variable type named Course                  
    int number;                                             // a Course can contain multiple variables
    std::string name; 

    Course(): number(101), name("Unknown") {                // default constructor
    }
    void setNumber(int n) {
        number = n;
    }  
    void setName(std::string n) {
        name = n;
    }
    int getNumber() {
        return number;
    }
    std::string getName() {
        return name;
    }
    void print() {
        std::cout << number << " " << name << std::endl;    // print member function
    }
};

void print(Course &c) {
    std::cout << c.number << " " << c.name << std::endl;    // print non-member function
}

int main() {
    std::cout << std::endl;

    Course c1;                  // call the Course constructor to initialize object c1
    Course c2;                  

    c2.setNumber(574);          // member function syntax variable.functionname()
    c2.setName("Python");
    
    c1.print();                 // call the print function on object c1
    print(c2);                  // non-member function syntax functionName(variable);

    std::cout << std::endl;
    return 0;
}
