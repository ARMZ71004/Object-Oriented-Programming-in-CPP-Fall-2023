// S. Trowbridge 2023
#include <iostream>

typedef int (*func) (int, int);     // typedef for a function pointer for a 2 int parameter int return function

int add(int a, int b) 
{
    return a+b;
}
int multiply(int a, int b) 
{
    return a*b;
}

void print(int a, int b, func f) 
{                                   // f is a function point parameter
    std::cout << f(a,b) << "\n";    // call the function pointed to by f
}

int main() 
{
    std::cout << std::endl;

    print(5, 6, add);               // call print with add function argument
    print(5, 6, multiply);          // call print with multiply function argument

    std::cout << std::endl;
    return 0;
}
