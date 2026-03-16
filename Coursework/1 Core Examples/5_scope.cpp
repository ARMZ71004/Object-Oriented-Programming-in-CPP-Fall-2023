// S. Trowbridge 2023
#include <iostream>

int x = 5;                              // global scope: x is accessible everywhere

void testValue(int n) {                 
    std::cout << n << std::endl;        // local scope: n is accessible 
    std::cout << x << std::endl;        // global scope: x is accessible
    //std::cout << i << std::endl;      // compiler error: i is not in scope
}

void testReference(int &r) {            // pass by reference
    //std::cout << i << std:: endl;     // compiler error: i is not in scope
}

// scope defines the accessiblity of a variable name
int main() {
    std::cout << std::endl;

    int i = 1;
    testValue(i);
    testReference(i);

    std::cout << x << std::endl;        // global scope: x is accessible
    std::cout << i << std::endl;        // local scope: i is accessible 
    //std::cout << n << std::endl;      // compiler error: n is not in scope
    //std::cout << r << std::endl;      // compiler error: r is not in scope 

    std::cout << std::endl;    
    return 0;
}
