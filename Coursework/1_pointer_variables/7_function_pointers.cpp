// S. Trowbridge 2023
#include <iostream>

int add(int a, int b) 
{                                               // function with 2 int parameters that returns an int
    return a+b;
}
int multiply(int a, int b) 
{                                               // function with 2 int parameters that returns an int
    return a*b;
}
void print( int a, int b, int (*f)(int, int) ) 
{                                               // function pointer as a parameter
    std::cout << (*f)(a,b) << "\n";             // call the function pointed to by f
}

int main() 
{
    std::cout << std::endl;

    int (*f)(int, int);                         // create a function pointer for functions with 2 int parameters that return an int

    f = add;                                    // point f to the add function
    std::cout << (*f)(5, 6) << "\n";            // explicitly dereference and call the sum function (first syntax)

    f = multiply;                               // point f to the multiply function
    std::cout << f(5, 6) << "\n\n";             // implicitly dereference and call the multiply function (second syntax)

    print(5, 6, add);                           // call print with add function pointer as argument
    print(5, 6, multiply);                      // call print with multiply function pointer as argument

    std::cout << std::endl;
    return 0;
}
