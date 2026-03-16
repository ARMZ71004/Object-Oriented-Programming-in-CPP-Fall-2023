// S. Trowbridge 2023
#include <iostream>

int main() {
    std::cout << std::endl;

    int i = 5;

    std::cout << i << " " << &i << std::endl;   // print the value of i and the memory address of i

    int *p = &i;                                // store the memory address of i into the pointer variable p

    std::cout << *p << " " << p << std::endl;   // print the value of i (deference p) and the memory address of i (value of p)

    std::cout << &i << " " << &p << std::endl;  // print memory address of i and p, note that they are different variables

    std::cout << std::endl;    
    return 0;
}

