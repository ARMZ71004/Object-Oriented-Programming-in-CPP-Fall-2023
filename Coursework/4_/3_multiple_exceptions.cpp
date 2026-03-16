// S. Trowbridge 2023
#include <iostream>

double dividePositive(double a, double b) 
{                                         // only divide positive numbers
    if(b == 0) { throw std::invalid_argument("Capacity must be greater than 0."); } // terminate function and throw an invalid_argument exception
    if(b<0 || a<0) { throw std::invalid_argument("Values must be positive."); }     // terminate function and throw an out_of_range exception
    return a/b;                                                                      
}
int main() 
{
    std::cout << std::endl;

    double n, d;
    std::cout << "Enter a numerator and denominator: ";
    std::cin >> n >> d;

    try {                                                                           
        std::cout << dividePositive(n, d);                                         
    }
    catch(const std::exception& e) {                                                // this will catch any standard c++ exception type
        std::cerr << "Error: " << e.what() << "\n";                                 
    }

    std::cout << "\nProgram Continues" << "\n";

    std::cout << std::endl;
    return 0;
}
