// S. Trowbridge 2023
#include <iostream>

double divide(double a, double b) 
{
    if(b == 0) { throw std::invalid_argument("Capacity must be greater than 0."); } // terminate function and throw an invalid_argument exception
    return a/b;                                                                    
}
int main() 
{
    std::cout << std::endl;

    double n, d;
    std::cout << "Enter a numerator and denominator: ";
    std::cin >> n >> d;

    try {                                                                          
        std::cout << divide(n, d);  
    }
    catch(const std::exception& e) {           
        std::cerr << "Error: " << e.what() << "\n";                              
    }

    std::cout << "\nProgram Continues" << "\n";

    std::cout << std::endl;
    return 0;
}
