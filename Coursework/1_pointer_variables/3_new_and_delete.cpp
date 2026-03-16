// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    // new allocates dynamic memory and returns its memory address
    // delete deallocates dynamic memory

    int *p = new int(5);                        // automatic variable p (pointer) points to a dynamic variable (integer)
    std::cout << *p << "\n";                    // derefence the pointer p to access the data

    std::string *s = new std::string("Hello");  // automatic variable s (pointer) points to a dynamic variable (integer)
    std::cout << *s << "\n";                    // derefence the pointer s to access the data

    delete p;                                   // deallocate the dynamic variable that p points to 
    delete s;                                   // deallocate the dynamic variable that s points to 

    std::cout << std::endl;
    return 0;                                   // all program memory is deallocated when the program ends
}
