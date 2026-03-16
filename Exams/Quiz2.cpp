#include<iostream>

//Identify the big-O time complexity of each of the following functions:

void f1(int n) {
    for(int i=0; i<(3*n+n); ++i) {
        std::cout << i << std::endl;
    }
    for(int i=0; i<(10*n); ++i) {
        std::cout << i << std::endl;
    }
}

//F1:O(n)
/*The big O time complexity of the F1 function is just 0(n) due to the two singular loops one of which asks for 4*n and the other 10*n*/

void f2(int n) {
    if(n==0) { return; }
        f2(n-1);
        f2(n-3);
}

//F2:O(2^n)
/*The big O time complexity of the F2 function is a binary recursion as what it asks for causes a tree of functions increasing the time complexity in an exponential way*/

void f3(int n) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            for(int k=0; k<n; ++k) {
                std::cout << i << std::endl;
            }
        }
    }
}

//F3:O(n^3)
/*The big O time complexity of the F3 function is a cubic recursion as n is going through a loop 3 times*/