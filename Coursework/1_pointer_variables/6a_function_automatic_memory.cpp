// S. Trowbridge 2023
#include <iostream>

int f1() 
{
    int i = 100;        // i is an automatic varible
    return i;           // i goes out of scope, then removed from the runtime stack and a temporary copy of i is returned
}


int& f2() 
{                       // NEVER return a local variable by reference
    int i = 10;         // i an automatic variable
    return i;           // i goes out of scope, then removed from the runtime stack and a garbage memory address is returned
}

int main() 
{
    std::cout << std::endl;

    int n = f1();
    std::cout << " n:\t" << n << std::endl;

    n = f2();                                   // assign n to garbage
    std::cout << " n:\t" << n << std::endl;     // print garbage (not an obvious error)

    std::cout << std::endl;
    return 0;
}
