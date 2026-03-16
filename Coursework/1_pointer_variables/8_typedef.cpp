// S. Trowbridge 2023
#include <iostream>

typedef int* debit;                 // define a global alias for the int* type
typedef int* credit;                // define a global alias for the int* type

void printLoss(debit d) 
{                                   // debit easier to read than int*
    std::cout << *d << std::endl;
}

void printGain(credit c) 
{                                   // credit easier to read than int*
    std::cout << *c << std::endl;
}

int main() 
{
    std::cout << std::endl;

    debit p = new int(5000);        // debit is really int*
    credit q = new int(10000);      // credit is really int*

    printLoss(p);
    printGain(q);

    std::cout << std::endl;
    return 0;
}
