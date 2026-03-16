// S. Trowbridge 2023
#include <iostream>

void init(int **p, int rows, int cols) 
{
    int x=1;
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            p[i][j] = x++;
        }
    }
}

void print(int **p, int rows, int cols) 
{
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            std::cout << p[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void printMemory(int **p, int rows, int cols) 
{
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            std::cout << &p[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() 
{
    std::cout << std::endl;

    int rows = 2, cols = 3;
    int **p = new int*[rows];                               // 1. create an partially contiguous array of rows
    for(int i=0; i<rows; ++i) { p[i] = new int[cols]();}  // 2. create an array of cols

    init(p, rows, cols);
    print(p, rows, cols);
    printMemory(p, rows, cols);

    for(int i=0; i<rows; ++i) { delete [] p[i]; }           // 1. delete each array of cols
    delete [] p;                                                // 2. delete the array of rows

    std::cout << std::endl;
    return 0;
}
