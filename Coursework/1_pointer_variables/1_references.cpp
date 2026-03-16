// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    int i = 5;

    int &r = i;                              // create a reference to i

    std::cout << i << " " << r << "\n\n";    // print values of i and r (same)

    std::cout << &i << " " << &r << "\n";    // print memory location of i and r (same)

    std::cout << std::endl;
    return 0;
}
