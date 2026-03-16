// S. Trowbridge 2023
#include <iostream>

void print(int *p, int size) 
{ 
    for(int i=0; i<size; ++i) {
        std::cout << *(p+i) << " "; // pointer arithmetic to print array values
    }
}

int main() 
{
    std::cout << std::endl;

    const int SIZE = 5;
    int a[SIZE] = {10, 20, 30, 40, 50};

    print(a, SIZE);   

    std::cout << std::endl;
    return 0;
}
