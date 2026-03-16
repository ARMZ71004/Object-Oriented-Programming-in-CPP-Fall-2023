// S. Trowbridge 2023
#include <iostream>

class B {
public:
};
class D final: public B {       // final specifies that D cannot be inherited from
public:
};
class DD: public D {            // DD cannot inherit from D
public:
};


int main() {
    std::cout << std::endl;

    D *d = new DD{};            // compiler error: DD cannot inherit from D because D has the final specifier

    std::cout << std::endl;
    return 0;
}
