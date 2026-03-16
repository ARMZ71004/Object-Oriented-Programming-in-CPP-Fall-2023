// S. Trowbridge 2023
#include <iostream>

template<typename T>  
void swapVal(T &a, T &b) {     
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    std::cout << std::endl;

    int x = 1, y = 2;
    char v = 'V', w = 'W';

    std::cout << x << " " << y << "\n";
    swapVal(x, y);                          // swap two integers
    std::cout << x << " " << y << "\n\n";

    std::cout << v << " " << w << "\n";
    swapVal(v, w);                          // swap two characters
    std::cout << v << " " << w << "\n";

    std::cout << std::endl;
    return 0;
}
