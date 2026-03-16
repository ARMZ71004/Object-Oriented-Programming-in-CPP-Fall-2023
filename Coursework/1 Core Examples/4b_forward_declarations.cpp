// S. Trowbridge 2023
#include <iostream>

// forward declarations: declare something before you define it (required for multi-file programs)

// function declarations: function name, return type and parameter list
void print(int n);                 
void increment(int &n);             

int main() {
    std::cout << std::endl;

    int i = 5;

    // function calls: function name, argument list
    print(i);                            
    increment(i);                   
    print(i);

    std::cout << std::endl;    
    return 0;
}

// function definitions: function name, return type, parameter list AND function body
void print(int n) {
    std::cout << n << std:: endl; 
}
void increment(int &n) {
    ++n;   
}
