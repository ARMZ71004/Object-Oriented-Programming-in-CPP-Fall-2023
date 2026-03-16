// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    int a[5] = {10, 20, 30, 40, 50};                    // standard array has a fixed size

    std::cout << "Address of a: " << a << "\n";         // a is of type int[5] and a stores the memory address of the first value
    std::cout << "Address of a: " << &a << "\n\n";      // the memory address of a is simultaneously the value of a
    std::cout << "Size of a: " << sizeof(a) << "\n\n";  // sizeof(x) to print the total amount of array memory in bytes

    // calculate memory addresses:
    // all positions from first address can be calculated using this formula:
    // size * index + startAddress
    // a[0] = 4 * 0 + 2000 = 2000
    // a[1] = 4 * 1 + 2000 = 2004
    // a[2] = 4 * 2 + 2000 = 2008 etc.
    for(int i=0; i<5; ++i) {std::cout << a[i] << "\t" << &a[i] << "\n";}

    std::cout << std::endl;
    return 0;
}
