// s. trowbridge 2020
#include <iostream>

// what is the time complexity?
void f1(int n) {
    for(int i=1; i<=(10*n); ++i) {
        std::cout << i << " ";
    }
}

// what is the time complexity?
void f2(int n) {
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            std::cout << n << " ";
        }
    }
    std::cout << std::endl;
}

// what is the time complexity?
void f3(int n) {
    if(n==0){ return; }
    for(int i=1; i<=n; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    f3(n-1);
}

int main( ) {
    std::cout << std::endl;

    f1(3);
    std::cout << "\n\n";
    f2(3);
    std::cout << "\n\n";
    f3(3);

    std::cout << std::endl;
    return 0;
}
