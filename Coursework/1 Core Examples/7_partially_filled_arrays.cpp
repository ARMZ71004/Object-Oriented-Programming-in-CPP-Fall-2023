// S. Trowbridge 2023
#include <iostream>

void print(int *a, int size) {              // print size values (data), not capacity values (data + garbage)   
    for(int i=0; i<size; ++i) {         
        std::cout << a[i] << " ";       
    }
    std::cout << std::endl;
}
void append(int *a, int capacity, int &size, int value) { 
    if(size < capacity) {                   // if there is room in the array add a value to the end,
        a[size] = value;                    // store the new value at index size (index size is the new last position in the array)
        ++size;                             // increment size since data was added, size must be passed by reference
    }
}
void deleteLast(int &size) {                // if we decrement size, the last value becomes garbage instead of data
    if(size > 0) {                          // if the array has data, remove the last value
        --size;
    }
}

int main() {
    std::cout << std::endl;

    // array indexes: 0    1    2    3    4    5    6    7    8    9        (CAPACITY values)
    // array data:    10   20   30   40   50   0    0    0    0    0        (size data, rest of the array is garbage)
    // memory:        3010 3014 3018 301c 3020 3024 3028 302c 3030 3034 

    const int CAPACITY = 10;                // total amount of values that the array can store
    int nums[CAPACITY] = {10,20,30,40,50};  // partially filled array of 10 values, 5 values of data followed by 5 garbage values
    int size = 5;                           // size tracks the amount of data (versus garbage) in the array

    std::cout << sizeof(nums) << std::endl; // print the amount of memory for this variable in bytes

    print(nums, size);
    append(nums, CAPACITY, size, 60);       // size is  updated because of pass by reference
    append(nums, CAPACITY, size, 70);       // size is updated because of pass by reference
    print(nums, size);
    deleteLast(size);                       // size decrements which makes the last value garbage instead of data
    print(nums, size);

    std::cout << std::endl;    
    return 0;
}

