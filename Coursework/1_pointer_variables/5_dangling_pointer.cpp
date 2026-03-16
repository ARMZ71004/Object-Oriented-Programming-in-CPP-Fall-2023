// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    int *p = new int(1);        // declare memory on the heap
    delete p;                   // deallocate the memory pointed to by p

    p = nullptr;                // point p to nullptr to avoid a dangling pointer
    if(p == nullptr) {          // assign p to a new pointer, if it does not point to anything else
        p = new int(100);
    }
    
    delete p;

    std::cout << std::endl;
    return 0;                   // all program memory is deallocated when the program ends
}
