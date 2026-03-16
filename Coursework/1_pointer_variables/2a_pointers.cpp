// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    int i = 5;

    int *p = &i;                             // create a pointer to i

    std::cout << i << " " << &i << "\n\n";   // print value and memory address of i  

    std::cout << i << " " << p << "\n\n";    // print value of i and p (the value of p is the memory address of i)

    std::cout << &i << " " << &p << "\n\n";  // print memory address of i and p (different, two different variables)

    std::cout << i << " " << *p << "\n\n";   // print value of i two different ways (deference p to access i)

    *p = 10;                                 // change the value of i by deferencing p and assigning it a value

    std::cout << i << " " << *p << "\n";     // the value of i was changed

    std::cout << std::endl;
    return 0;
}
