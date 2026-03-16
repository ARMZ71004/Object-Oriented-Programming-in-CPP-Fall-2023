// S. Trowbridge 2023
#include <iostream>

int* f1() 
{                 
    int *i;
    int n = 10;                 // n is automatic memory
    i = &n;                     // point i to n
    return i;                   // n and i go out of scope (what is the lifetime of the integer variable?)
}

int* f2() 
{
    int *i = new int(100);      // point i to a dynamic variable
    return i;                   // i goes out of scope (what is the lifetime of the integer variable?)
}

int main() 
{
    std::cout << std::endl;

    int *p = f1();              // what is the problem here?
    std::cout << *p << "\n";    

    int *q = new int{10};
    q = f2();                   // what is the problem here?

    delete q;

    std::cout << std::endl;
    return 0;
}
