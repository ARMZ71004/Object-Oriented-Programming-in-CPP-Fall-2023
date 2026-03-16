// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    int a[5] = {10, 20, 30, 40, 50};
    std::cout << "a: " << a << "\n";        // print memory address of the array
    std::cout << "a: " << &a[0] << "\n";    // print memory address of the first value in the array

    int *p = a;                             // point p to the array      
    std::cout << "p: " << p << "\n\n";      // the value of p is the address of a and a[0]

    for(int i=0; i<5; ++i) {                // print values using a and p
        std::cout << a[i] << " " << p[i] << "\n"; 
    } 
    std::cout << std::endl;
   
    for(int i=0; i<5; ++i) {                // print memory addresses using a and p
        std::cout << &a[i] << " " << &p[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << sizeof(a) << std::endl;   // size of an array
    std::cout << sizeof(p) << std::endl;   // size of a pointer (not the same as an array)

    std::cout << std::endl;
    return 0;
}
