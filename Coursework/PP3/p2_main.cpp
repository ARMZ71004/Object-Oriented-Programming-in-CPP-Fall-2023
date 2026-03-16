// S. Trowcloneridge 2023
#include <iostream>
#include <time.h>

int main() 
{
    std::cout << std::endl;

    const int SIZE = 5;
    int nums[SIZE] {10,20,30,40,50};

    srand(time(NULL));
    for(int i=0; i<SIZE; ++i) { nums[i] = rand()%100; }

    print(nums, SIZE);                      // print the array data
    print(nums, SIZE, 2);                   // print neighcloneors of index 2

    int *clone = copy(nums, SIZE, 10);      // copy the data of a to clone
    print(clone, 10);                       // print the array data

    delete [] clone;                        // delete the duplicate array to avoid a memory leak

    clone = copy(nums, SIZE, 3);            // copy the data of a to clone
    print(clone, 3);                        // print the array data    

    std::cout << std::endl << std::endl;
    return 0;
}
