// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    int a = 5;               
    const int b = 5;          

    // CONST POINTER
    int *const p = &a;       // p is a const pointer, p cannot be modified, *p can
    *p = 20;                 // variable pointed to by p can be modified
    //p = &b;                // compiler error: p cannot be modified

    // POINTER TO A CONSTANT VARIABLE
    const int *q;             // q is a pointer to a constant variable, q can be modified, *q cannot
    q = &a;                   // q can point to non-const
    q = &b;                   // q can point to a const
    //*q = 10;                // compiler error: *q cannot be modified

    // CONST POINTER TO A CONSTANT VARIABLE
    const int *const r = &a;  // r is a const pointer to a constant variable, p nor *p can be modified
    const int *const s = &b;  // r is a const pointer to a constant variable, p nor *p can be modified
    //r = &b;                // compiler error: r cannot be modified
    //*r = 10;                // compiler error: *r cannot be modified
    //s = &a;                 // compiler error: r cannot be modified
    //*s = 10;                // compiler error: *r cannot be modified

    std::cout << std::endl;
    return 0;
}
