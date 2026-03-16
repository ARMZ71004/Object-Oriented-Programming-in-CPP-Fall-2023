// S. Trowbridge 2023
#include <iostream>

void f1(int *i) 
{                                   // pass pointer by value, i is a copy of p
    *i = 100;                       // i can be used to update the variable pointed to by p
}
                                    // dynamic memory created in a function can remain in memory after function ends
int* f2() 
{                                   // return a pointer (a memory address) by value
    int *i = new int(1000);         // assign a pointer to dynamic memory
    return i;                       // i goes out of scope and a copy of i is returned (the memory address of the dynamic memory)
}

void f3(int *&i) 
{                                   // pass pointer by reference (rare occurence), i is the same variable as p
    delete i;                       // i can delete data of variable p points to 
    i = new int(10000);             // i can point p to new dynamic memory 
}

int main() 
{
    std::cout << std::endl;

    int *p = new int{10};            // allocate dynamic memory pointed to by p

    f1(p);                          // update the variable p points to
    std::cout << *p << std::endl;

    int *q = f2();                  // point q to the dynamic memory retuned by f2
    std::cout << *q << std::endl;

    f3(p);                          // safely assign p to new dynamic memory then assign q to point to this new memory
    std::cout << *p << std::endl;

    delete p;

    std::cout << std::endl;
    return 0;
}
