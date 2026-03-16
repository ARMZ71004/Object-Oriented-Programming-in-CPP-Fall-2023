#include<iostream>
const int MAX_CAPACITY = 25;
int* grow(int *a, int &capacity, int size) {
    int z = capacity * 2;
    if(z > MAX_CAPACITY){
        throw std::length_error("Array exceeds maximum data size.");
    }
    int *temp = new int[z];
    for (int i = 0; i < size; i++) {
        *(temp+i) = *(a+i);
    }
    delete[] a;
    capacity = z;
    return temp;
}

int* append(int *a, int &capacity, int &size, int val) 
{
 if(size == capacity) { a = grow(a, capacity, size); }
 a[size++] = val;
 return a;
}

void print(int *a, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{ 
 std::cout << std::endl;

 int capacity = 5;
 int size=0;
 int *a = new int[capacity];

 try {
 for(int i=0;i<30; ++i) { a = append(a, capacity, size, (i+1)*10); }
 } catch(const std::length_error &e) {
 std::cerr << e.what() << "\n"; 
 }

 print(a, size);
 delete [] a;
 std::cout << std::endl;
 return 0;
}
