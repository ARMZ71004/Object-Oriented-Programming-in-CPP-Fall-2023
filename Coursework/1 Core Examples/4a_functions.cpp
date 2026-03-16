// S. Trowbridge 2023
#include <iostream>

void print(int n) {                 // pass by value: value of i is copied to n
    std::cout << n << std:: endl;   
}
void increment(int &n) {            // pass by reference: memory address of i is coped to n (int &n = i;)
    ++n;                            
}
void increment(int &n, int x) {     // overloaded function (same name, different parameter list)
    n+=x;
}

int main() {
    std::cout << std::endl;

    int i = 5;

    print(i);                       // the argument i is sent to the parameter n        
    increment(i);                   
    print(i);
    increment(i, 5);
    print(i);
    
    // print("Hello");              // compiler error: argument type must match parameter type

    std::cout << std::endl;    
    return 0;
}
