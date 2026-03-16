// S. Trowbridge 2023
#include <iostream>

class Add {
public:
    int operator()(int x, int y) { return x+y; }        // overload () 
};

class Multiply {
private:
    int count = 0;                                      // track number of objects (state)
public:
    int operator()(int x, int y) {                      // overload ()
      count++;                                          // change count (update state)
      return x*y;
    }
    int getCount() const { return count; }
};

void print(int a, int b, Add *obj) {
    std::cout << (*obj)(a,b) << "\n";                   // call the add function
}

void print(int a, int b, Multiply *obj) {
    std::cout << (*obj)(a,b) << "\n";                   // call the multiply function
}

int main() {
    std::cout << std::endl;

    Add add;
    Multiply *m = new Multiply();

    std::cout << add(5,6) << "\n";                      // 5+6 - syntax for a function object
    std::cout << (*m)(5,6) << "\n\n";                   // 5*6 - syntax for a pointer to a function object

    std::cout << m->getCount() << "\n\n";               // check state (function objects have memory unlike functions)

    print(5, 6, &add);
    print(5, 6, m);

    std::cout << std::endl;
    return 0;
}
