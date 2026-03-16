// S. Trowbridge 2023
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <algorithm>

void print(int *a, int size);
int* grow(int *a, int &capacity);
void push_back(int *a, int &capacity, int &size, int value);            // 0(1) - append or add data to the end of the array
void push_front(int *a, int &capacity, int &size, int value);           // O(n) - prepend or add data to the front of the array 
void pop_back(int *a, int &size);                                       // O(1) - remove last value
void pop_front(int *a, int &size);                                      // O(n) - remove first value
void duplicate(int *a, int *b, int size);                               // O(n) - duplicate an array

#endif