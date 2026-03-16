// S. Trowbridge 2023
#include "Array.h"

void print(int *a, int size) 
{
    for(int i=0; i<size; ++i) { std::cout << a[i] << " "; }
    std::cout << "\n";
}
int* grow(int *a, int &capacity)
{
    int *temp = new int[capacity*2];                                // temp is twice the size of array a
    std::copy(a, a+capacity, temp);                                 // copy values from a[0] through a[capacity] to temp[0] through temp[capacity]
    capacity *= 2;                                                  // double the capacity
    delete [] a;                                                    // delete array a
    return temp;                                                    // return ptr to temp
}
void push_back(int *a, int &capacity, int &size, int value)         
{
    if(size == capacity) {                                          // array is full: grow
        grow(a, capacity);
    }
    a[size] = value;                                                // store value at end of the array
    ++size;                                                         // increment size
}
void push_front(int *a, int &capacity, int &size, int value)         
{
    if(size == capacity) {                                          
        grow(a, capacity);
    }
    std::copy(a, a+size, a+1);                                      // right shift - copy values from a[0] through a[size-1] to a[1] through a[size]
    a[0] = value;                                                   // store value at front of the array
    ++size;                                                         
}
void pop_back(int *a, int &size)                                    
{                              
    if(size > 0) { --size; }                                        // array has values : decrement size to make last value no longer "accessible"
}
void pop_front(int *a, int &size)                                   
{
    std::copy(a+1, a+size, a);                                      // left shift - copy values from a[1] through a[size-1] to a[0] through a[size-2]
    --size;                                                         
}
void duplicate(int *a, int *b, int size)                            // copy size values from array a to array b
{
    std::copy(a, a+size, b);
}