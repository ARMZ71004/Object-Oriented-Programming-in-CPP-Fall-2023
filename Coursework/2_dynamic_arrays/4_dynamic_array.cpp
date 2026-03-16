// S. Trowbridge 2023
#include <iostream>

void print(int *p, int size) 
{
    for(int i=0; i<size; ++i) {
        std::cout << p[i] << " ";       // print value
        std::cout << &p[i] << "\n";     // print memory address (contiguous)
    }
    std::cout << std::endl;
}

void initialize(int *p, int size) 
{
    for(int i=0; i<size; ++i) {
        p[i] = (i+1)*10;
    }
}

int main() 
{
    std::cout << std::endl;

    const int SIZE = 10;
    int *a = new int[SIZE];             // create a dynamic array

    std::cout << sizeof(a) << "\n\n";   // print the size of the array

    print(a, SIZE);                     // print the contents of the dynamic array
    initialize(a, SIZE);                // store the powers of 10 into the array
    print(a, SIZE);

    delete [] a;                        // delete the dynamic array

    std::cout << std::endl;
    return 0;
}
