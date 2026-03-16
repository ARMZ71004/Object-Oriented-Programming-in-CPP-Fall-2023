// S. Trowbridge 2023
#include <iostream>

template<typename T>
T add(T a, T b) {                                // add values
    return a+b;
}

template<typename T>                            // overloaded function: deference pointers then add values
T add(T *a, T *b) {
    return (*a) + (*b);
}

int main() {
    std::cout << std::endl;

    int x=1, y=2;

    std::cout << add(x, y) << std::endl;        // call original function for values
    std::cout << add(&x, &y) << std::endl;      // call overloaded function for pointers 

    std::cout << std::endl;
    return 0;
}
