// S. Trowbridge 2023
#include <iostream>

int main() 
{
    std::cout << std::endl;

    double d = 3.14, e = 3.14;            
    double *p = &d, *q = &d;                // point p and q to d

    std::cout << d << " "  << &d << "\n";   // value and memory address of d
    std::cout << *p << " " << *q << "\n";   // dereference p and q (value of d)
    std::cout << p << " " << q << "\n\n";   // value of p and q (memory address of d)

    if(&p == &q)                            // what are we comparing?
        std::cout << "&p == &q" << "\n";
    else
        std::cout << "&p != &q" << "\n";

    if(p == q)                              // what are we comparing?
        std::cout << "p == q" << "\n";
    else
        std::cout << "p != q" << "\n";

    q = &e;                                 // point q to e         

    if(*p == *q)                            // what are we comparing?
        std::cout << "*p == *q" << "\n";
    else
        std::cout << "*p != *q" << "\n";

    std::cout << std::endl;
    return 0;
}
