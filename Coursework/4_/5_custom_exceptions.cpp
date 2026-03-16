// S. Trowbridge 2023
#include <iostream>

struct upperCaseException : public std::exception                           // custom exception type "inherits" from std::exception 
{
    const char* what() const noexcept {                                     // must define the what function which in of itself cannot throw an exception (noexcept)
        return "Uppercase letters are not allowed.";
    }
};

int main()                                                                  // https://en.cppreference.com/w/cpp/error/exception 
{         
    std::cout << std::endl;

    char letter;

    try {
        std::cout << "Enter a lowercase letter: ";
        std::cin >> letter;
        if( isupper(letter) ) { throw upperCaseException(); }               // if the letter is uppercase, throw the custom exception
    }
    catch( const upperCaseException &e) {
        std::cerr << e.what() << "\n"; 
    }

    std::cout << "\nProgram Continues" << "\n";

    std::cout << std::endl;
    return 0;
}
