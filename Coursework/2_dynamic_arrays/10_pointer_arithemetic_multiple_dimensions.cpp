// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    int rows = 2, cols = 3;

    /* ARRAY OF ARRAYs *******************************************************************/

    int **p = new int*[rows];                           // create a dynamic array of arrays
    for(int i=0; i<rows; i++) { p[i] = new int[cols];}

    int num = 1;
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            *(*(p+i)+j) = num++;                        // same as a[i][j] = num++
        }
    }
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            std::cout << *(*(p+i)+j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    for(int a=0; a<rows; ++a) { delete [] p[a]; }       // delete the array of arrays
    delete [] p;

    /* 2D ARRAY ***************************************************************************/

    int *a = new int[rows * cols];                      // create a dynamic 2d array

    num = 1;
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j)
             *(a+(i*cols+j)) = num++;                   // same as a[i*cols+j] = num++
    }
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            std::cout << *(a+(i*cols+j)) << " ";
        }
        std::cout << "\n";
    }   
    
    delete [] a;                                        // delete the 2d array

    std::cout << std::endl;
    return 0;
}
