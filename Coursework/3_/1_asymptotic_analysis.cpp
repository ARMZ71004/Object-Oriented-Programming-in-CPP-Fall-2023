#include <iostream>

// constant time complexity (O(1))
void printValue(int a[], int i) {
    std::cout << a[i] << " ";
}

// linear time complexity (O(n))
void print(int a[], int n) {
    for(int i=0; i<n; ++i) {
        std::cout << a[i] << " ";
    }
}

// linear recursion - linear time complexity (O(n))
void countDown(int n) {
    if(n==0){ return; }
    std::cout << n << " ";
    countDown(n-1);
}

// quadratic time complexity (O(n^2))
void print(int a[][3], int size) {
    for(int i=0; i<size; ++i) {
        for(int j=0; j<size; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// binary recursion - exponential time complexity (O(2^n))
// n = 1 2 3 4 5 6 7  8 ...
// e = 1 1 2 3 5 8 13 21 ...
// print the nth element of the fibonacci sequence
long fibonacci(int n) {
     // base case
    if(n<2) { return n; }
    // recursive task
    return fibonacci(n-1) + fibonacci(n-2);
}

// logarithmic time complexity (O(log n))
// search for value
int binarySearch(int a[], int size, int value) {
    int start = 0, end = size - 1;
    while(start <= end) {
        int middle = (start+end) / 2;
         // print start, middle, end to see the process
        std::cout << start << " " << middle << " " << end << "\n";
        if(a[middle] == value) {
            return middle;
        } else if(a[middle] < value) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return -1;
}

// linear time complexity (O(n))
// search for value
int linearSearch(int a[], int size, int value) {
    for(int i=0; i<size; ++i) {
        std::cout << i << " ";
        if(a[i] == value) { return i; }
    }
    return -1;
}


int main( ) {
    std::cout << std::endl;

    int list[10] = {10,20,30,40,50,60,70,80,90,100};
    int matrix[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

    // print the length of hello
    std::cout << "PRINT AN ELEMENT OF AN ARRAY\n";
    printValue(list, 6);
    std::cout << "\n\n";

    // print a one dimensional array
    std::cout << "PRINT ONE DIMENSIONAL ARRAY\n";
    print(list, 10);
    std::cout << "\n\n";

    // countdown from n to 1
    std::cout << "COUNTDOWN\n";
    countDown(10);
    std::cout << "\n\n";

    // print a two dimensional array
    std::cout << "PRINT TWO DIMENSIONAL ARRAY\n";
    print(matrix, 3);
    std::cout << "\n";

    // compare different values of n to see performance difference
    std::cout << "FIBONACCI:\n" << fibonacci(10) << "\n\n\n";


    std::cout << "BINARY VS. LINEAR SEARCH:\n\n";

    // worst case, the element 11 is not in the array (4 iterations)
    int *a = new int[10];
    for(int i=0; i<10; ++i) { a[i] = i; }
    std::cout << binarySearch(a, 10, 11) << "\n\n";    // return -1 since 11 not in the array
    std::cout << linearSearch(a, 10, 11) << "\n\n\n\n";    // return -1 since 11 not in the array

    // worst case, the element 213 is not in the array (7 iterations)
    int *b = new int[100];
    for(int i=0; i<100; ++i) { b[i] = i; }
    std::cout << binarySearch(b, 100, 213) << "\n\n";  // return -1 since 213 not in the array
    std::cout << linearSearch(b, 100, 213) << "\n\n\n\n";  // return -1 since 213 not in the array

    // worst case, the element 5152 is not in the array (10 iterations)
    int *c = new int[1000];
    for(int i=0; i<1000; ++i) { c[i] = i; }
    std::cout << binarySearch(c, 1000, 5152) << "\n\n";  // return -1 since 5152 not in the array
    std::cout << linearSearch(c, 1000, 5152);  // return -1 since 213 not in the array

    std::cout << std::endl;
    return 0;
}
