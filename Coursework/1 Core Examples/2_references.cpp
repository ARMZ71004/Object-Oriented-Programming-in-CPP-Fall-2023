// S. Trowbridge 2023
#include <iostream>

int main() {
    std::cout << std::endl;

    int i = 5;

    std::cout << i << " " << &i << std::endl;   // the addressOf operator (&) returns the memory address of a variable

    int &r = i;                                 // create another name for i, r is a reference to variable i

    std::cout << i << " " << r << std::endl;    // value of i and r are identical

    std::cout << &i << " " << &r << std::endl;  // memory address of i and r identical, they are the same variable

    std::cout << std::endl;    
    return 0;
}

