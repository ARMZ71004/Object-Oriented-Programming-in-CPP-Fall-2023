// S. Trowbridge 2023
#include <iostream>

class Course {
private:
    int number;
public:
    Course(): Course(0) {}
    Course(int n): number(n) {}
    void thisPrint() const 
    {
        std::cout << this << "\n";              // print the pointer to the calling object
        std::cout << *this << "\n\n";           // print the calling object (requires << overload)
    }
    bool operator ==(const Course& c) const 
    { 
        return this->number == c.number;        // use this-> to access a data member of the callingo object
    }
    friend std::ostream& operator<<(std::ostream& out, const Course &c);
};

std::ostream& operator<<(std::ostream& out, const Course &c) { return (out << c.number); }

int main() 
{
    std::cout << std::endl;

    Course c1{575};
    Course c2{575};

    std::cout << &c1 << "\n";                   // print object memory address
    std::cout << c1 << "\n\n";                  // print object (requires << overload)

    c1.thisPrint();                             // do the same thing using "this"

    std::cout << std::endl;
    return 0;
}
