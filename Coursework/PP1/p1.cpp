#include <iostream>
#include <time.h>
using namespace std;

void print(int a[], int size){
    for(int i = 0; i<size; ++i){
        std::cout << a[i] << std::endl;
    }
}

void getMax(int *a,int size){
    for(int i = 0; i<size; ++i){
        while (a[i-1] < a[i]){
            int max = a[i];
        }
    }
    cout << max <<endl;
}

int main() {
    std::cout << std::endl;

    const int CAPACITY = 10;
    int a[CAPACITY];
    int size = 6;

    srand(time(NULL));
    for(int i=0; i<size; ++i) { a[i] = rand()%100; }


    print(a, size);
    
    std::cout << getMax(a, size) << std::endl;

/*
    swap(a[0],a[5]);
    print(a, size);
    std::cout << std::endl;

    insertFirst(a, CAPACITY, size, 100);
    print(a, size);

    deleteFirst(a, size);
    print(a, size);
    deleteFirst(a, size);
    print(a, size);   
*/

    std::cout << std::endl;
    return 0;
}