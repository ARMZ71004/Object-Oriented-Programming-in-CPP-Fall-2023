// S. Trowbridge 2023
#include <iostream>
#include "Array.h"

int main() 
{
    std::cout << std::endl;

    int capacity = 10;                                              // amount of memory for the array
    int size = 0;                                                   // amount of data
    int *a = new int[capacity];                                     // allocate an array of capacity values

    std::cout << "PUSH\n";
    push_back(a, capacity, size, 300);                              // insert back
    print(a, size);    
    push_back(a, capacity, size, 400);                              // insert back
    print(a, size);    
    push_back(a, capacity, size, 500);                              // insert back
    print(a, size);    
    push_back(a, capacity, size, 600);                              // insert back
    print(a, size);
    
    push_front(a, capacity, size, 200);                             // insert front
    print(a, size);    
    push_front(a, capacity, size, 100);                             // insert front
    print(a, size);  

    std::cout << "\nPOP\n";
    pop_back(a, size);                                              // erase first value
    pop_front(a, size);                                             // erase last value
    print(a, size);          

    std::cout << "\nDUPLICATE\n"; 
    int capacity_b = capacity;                                      // b capacity (initially the same as capacity of a)
    int size_b = size;                                              // b size (initially same as size of a)
    int *b = new int[capacity_b];                                   // dynamic array of capacity_b values
    duplicate(a, b, size);                                          // duplicate list without sharing memory
    print(a, size);                                                 
    print(b, size_b);

    std::cout << "\nMEMORY INDEPENDENCE\n";  
    delete [] a;                                                    // delete dynamic memory of a    
    print(b, size_b);                                               // b should contain all values
    delete [] b;                                                    // delete dynamic memory

    std::cout << std::endl;
    return 0;
}


