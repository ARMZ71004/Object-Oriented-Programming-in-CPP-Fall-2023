// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    int i=5, j=15;         

    int *p = nullptr;           // initalize p with nullptr  
    p = &i;                     // p points to i
    *p = 10;                    // dereference p to modify i

    std::cout << i << "\n";     // print i

    p = &j;                     // p points to j
    std::cout << *p << "\n";    // print j by deferencing p

    int *a, b;                  // declare an int pointer a and an int b
    int c, *d;                  // declare an int c and an int pointer d
    double *e, *f;              // declare two double pointers c and d

    std::cout << std::endl;
    return 0;
}
