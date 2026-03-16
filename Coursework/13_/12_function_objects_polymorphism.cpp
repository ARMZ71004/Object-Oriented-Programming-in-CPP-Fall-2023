// S. Trowbridge 2023
#include <iostream>

class Maths {                             // abstract class
public:
    virtual int operator()(int n) = 0;    // pure virtual function
    virtual ~Maths() {}                   // virtual destructor
};
class Summation: public Maths {           // derived class
public:
    int operator()(int n) override {      // compoute summation of n
        int s=0;
        for(int i=1; i<=n; ++i) { s+=i; }
        return s;
    }
};
class Factorial: public Maths  {          // derived class
public:
    int operator()(int n) override {      // recursively compute n factorial
        if(n==1) return 1;
        return (*this)(n-1)*n;            // recursive function call
    }
};

int math_func(int n, Maths *m) {          // Maths ptr parameter
    return (*m)(n);                       // call the () overload function of the object pointed to by m
}

int main() {
    std::cout << std::endl;

    Summation s;  
    Factorial *f = new Factorial();

    std::cout << s(5) << "\n";              // compute summation of 5 
    std::cout << (*f)(5) << "\n\n";         // compute 5 factorial

    Maths *m;
    m = new Summation();                    // upcast - maths ptr to summation object
    std::cout << math_func(5, m) << "\n";   // compute summation of 5

    m = new Factorial();                    // upcast - maths ptr to factorial object
    std::cout << math_func(5, m) << "\n";   // compute 5 factorial 

    std::cout << std::endl;
    return 0;
}
