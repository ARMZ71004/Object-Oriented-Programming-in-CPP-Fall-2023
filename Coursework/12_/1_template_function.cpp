// S. Trowbridge 2023
#include <iostream>

template<typename T>                        // T defines a type
T add(T a, T b) {                           // T is expanded to the actual type at compile time
    return a + b;
}

int main() {
    std::cout << std::endl;

    std::cout << add(5, 7) << "\n";         // sum two integers
    std::cout << add(5.5, 3.2) << "\n";     // sum two doubles

    std::string s1 = "Hi ";
    std::string s2 = "There";
    std::cout << add(s1, s2) << "\n";       // concatenate two strings

    std::cout << std::endl;
    return 0;
}
