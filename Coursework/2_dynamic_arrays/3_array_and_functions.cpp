// S. Trowbridge 2023
#include <iostream>

void print1(int p[], int size) 
{                                                       // int p[] parameter
    std::cout << "Size of p: " << sizeof(p) << "\n";    
    std::cout << "Value of p: " << p << "\n";           
    for(int i=0; i<size; ++i) {
        std::cout << p[i] << " ";                       // print values
        std::cout << &p[i] << "\n";                     // print memory addresses
    }
    std::cout << std::endl;    
}

void print2(int *p, int size) 
{                                                       // int *p parameter ( int[10] decays to int* )
    std::cout << "Size of p: " << sizeof(p) << "\n";    
    std::cout << "Value of p: " << p << "\n";           
    for(int i=0; i<size; ++i) {
        std::cout << p[i] << " ";                       // print values
        std::cout << &p[i] << "\n";                     // print memory addresses
    }
    std::cout << std::endl;
}

int main() 
{
    std::cout << std::endl;

    const int SIZE = 10;
    int a[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    std::cout << "Main:" << "\n";
    std::cout << "Size of a: " << sizeof(a) << "\n";    // print size of int[10]
    std::cout << "Value of a: " << a << "\n\n";         // print memory address of the array

    print1(a, SIZE);
    print2(a, SIZE);

    std::cout << std::endl;
    return 0;
}
