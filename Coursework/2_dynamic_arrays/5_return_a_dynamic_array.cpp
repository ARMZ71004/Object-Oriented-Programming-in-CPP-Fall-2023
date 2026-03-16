// S. Trowbridge 2023
#include <iostream>

int* returnAnArray(int size) {              // return a pointer to the dynamic array
    int *a = new int[size];
    for(int i=0; i<size; ++i) { a[i] = i;}
    return a;
}

void print(int *q, int size) {
    for(int i=0; i<size; ++i) { std::cout << q[i] << " ";}
}

int main() 
{
    std::cout << std::endl;

    int size = 10;

    int *p = returnAnArray(size);           // p points to the returned dynamic array
    print(p, size);                         // print the dynamic array
    delete [] p;                            // delete the dynamic array

    std::cout << std::endl;
    return 0;
}
