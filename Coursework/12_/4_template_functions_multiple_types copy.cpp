// S. Trowbridge 2023
#include <iostream>

template<typename A, typename B>                                    // A and B are distinct types
void output(A a, B b) {
    std::cout << "Output two types: " << a << " " << b << "\n";
}

template <typename T, typename U, typename V>                       // T U and V are distinct types (can be same or different)
V output(T a, U b, V c) {
    std::cout << "Output two types: " << a << " " << b << "\n";
    std::cout << "Return another: ";
    return c;
}

int main() {
    std::cout << std::endl;

    int i = 1;
    float f = 2.5;
    char c = 'A';

    output(i, f);                                                   // output two different types
    output(i, i);                                                   // output two same types  

    std::cout << std::endl;

    std::cout << output(i, f, c) << std::endl;                      // output two different types, return another
    std::cout << output(5, 6, 7) << std::endl;                      // output and return same types

    std::cout << std::endl;
    return 0;
}
