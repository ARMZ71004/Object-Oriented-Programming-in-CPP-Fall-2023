#include <iostream>

int main( ) 
{
    std::cout << std::endl;

    int size, newSize;
    std::cout << "Enter a size: ";
    std::cin >> size;
    std::cout << "\n";

    int *p = new int[size]();
    std::cout << "Original: " << "\n";
    initialize(p, size);
    print(p, size);

    std::cout << "Enter a new size: ";
    std::cin >> newSize;
    std::cout << "\n";

    p = grow(p, size, newSize);
    std::cout << "After grow: " << "\n";
    print(p, newSize);

    std::cout << std::endl;
    return 0;
}
