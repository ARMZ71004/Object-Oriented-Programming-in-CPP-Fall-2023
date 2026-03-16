// S. Trowbridge 2023
#include <iostream>

void print(int *p, int rows, int cols) 
{ 
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            std::cout << p[i * cols + j] << " ";           // first row index are 0 1 2, second row index are 3 4 5      
        }
        std::cout << std::endl;
    }
}

void printMemory(int *p, int rows, int cols) 
{                
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            std::cout << &p[i * cols + j] << " ";          // first row index are 0 1 2, second row index are 3 4 5   
        }
        std::cout << std::endl;
    }
}

int main() 
{
    std::cout << std::endl;

    int rows = 2, cols = 3;
    int *a = new int[rows * cols] {1, 2, 3, 4, 5, 6};   // create a contigous dynamic array of integers

    print(a, rows, cols);
    printMemory(a, rows, cols);   

    delete [] a;                                        // delete the dynamic array

    std::cout << std::endl;
    return 0;
}
