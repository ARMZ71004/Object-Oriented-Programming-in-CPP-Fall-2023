// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    int *p = new int(1);    // allocate a dynamic variable
    p = new int(2);         // memory leak (first dynamic variable was not deleted and is no longer accessible)

                            // 1. avoid memory leaks by deleting dynamic memory that is no longer used
    int *q = new int(1);    // allocate a dynamic variable
    delete q;               // deallocate the original dynamic variable
    q = new int(2);         // allocate a new dynamic variable

                            // 2. avoid memory leaks by ensuring there is always a way to access a dynamic variable
    int *r = new int(1);    // allocate a dynamic variable
    int *backup = r;        // create a second pointer to access the dynamic variable (retain access to the dynamic memory)
    r = new int(2);         // repoint r to a new dynamic variable

    delete p;
    delete q;
    delete r;
    delete backup;

    std::cout << std::endl;
    return 0;               // all memory is recycled when program ends
}
