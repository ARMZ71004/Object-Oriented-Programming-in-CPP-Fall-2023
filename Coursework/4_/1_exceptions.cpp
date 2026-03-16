// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    double n, d;
    std::cout << "Enter a numerator and denominator: ";
    std::cin >> n >> d;

    try {                                                                                   // code to try
        if(d == 0) { throw std::invalid_argument("Capacity must be greater than 0."); }     // throw an invalid argument exception with an error message
        std::cout << n/d << "\n";                                                           // code is only run if d != 0
    }
    catch(const std::exception& e) {                                                        // code is run only if an exception is thrown
        std::cerr << "Error: " << e.what() << "\n";                                         // the what function retrieves the error message
    }

    std::cout << "\nProgram Continues to Run" << "\n";

    std::cout << std::endl;
    return 0;
}
