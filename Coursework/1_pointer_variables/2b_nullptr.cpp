// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    int *p;                 // declare a pointer (p value is garbage)

    int *q = nullptr;       // initialize a pointer to nullptr (points to nothing)

    if(q == nullptr) {      // test if q points to nothing (easier to test this then if p points to garbage)
        std::cout << "Q currently points to nothing." << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
