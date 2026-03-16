// S. Trowbridge 2023
#include <iostream>

// 1. Array functions require the array and the size as input parameters
// 2. Array memory address is passed by value to a pointer, this is known as passing a pointer by value
void print(int *a, int size) {          
    for(int i=0; i<size; ++i) {                 // iterate through valid indexes: 0 to size-1
        std::cout << a[i] << " ";               // access each value by index using the bracket operator 
    }
    std::cout << std::endl;
}
void replace(int *a, int size, int index, int value) {
    if(index >=0 && index <size) {              // if the index is legal (0 to size-1),
        a[index] = value;                       // replace the data at index with the new value
    }
}

int main() {
    std::cout << std::endl;

    // array indexes: 0    1    2    3    4     (indexes run from 0 to size-1)
    // array data:    10   20   30   40   50 
    // memory:        3010 3014 3018 301c 3020  (each integer variable takes up 4 bytes of space)

    const int SIZE = 5;                         // total number of values in the array
    int nums[SIZE] = {10,20,30,40,50};          // create an assign data to an array of SIZE values

    std::cout << sizeof(nums) << std::endl;     // print the amount of memory for this variable in bytes

    print(nums, SIZE);
    replace(nums, SIZE, 3, 4000);               // replace the array value at index 3 with 4000
    print(nums, SIZE);

    std::cout << std::endl;    
    return 0;
}
