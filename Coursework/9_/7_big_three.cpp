// S. Trowbridge 2023
#include <iostream>

class Course {
private:
    std::string prof;                                               // automatic data member
    int *number;                                                    // dynamic data member
public:
    Course(): Course(0, "") {}
    Course(int n, std::string p): number(new int(n)), prof(p) {}

    Course(const Course &rhs);                                      // copy constructor
    Course& operator=(const Course &rhs);                           // assignment overload
    Course(Course &&rhs) noexcept = default;                        // move constructor (default: use the implicit definition provided by the compiler)
    Course& operator=(Course &&rhs) noexcept = default;             // move assignment overload (default: use the implicit definition provided by the compiler)
    ~Course();                                                      // destructor

    friend void swap(Course &lhs, Course &rhs) noexcept;            // swap required by assignment overload to steal temp object heap data

    friend std::ostream& operator<<(std::ostream& out, const Course &rhs);
};

Course::Course(const Course &rhs):                                  // copy constructor     
    number( new int( *(rhs.number) ) ),                             
    prof(rhs.prof) 
{}                                               
Course& Course::operator=(const Course &rhs) 
{                                                                   // assignment overload
    Course tmp{rhs};                                                
    //std::cout << tmp << std::endl;
    swap(*this, tmp);                                               
    //std::cout << tmp << std::endl;    
    return *this;                                                   
}
Course::~Course() 
{                                                                   // destructor
    delete number;                                                  
}
void swap(Course &obj, Course &tmp) noexcept 
{                                                                   // swap
    using std::swap;                                                
    swap(obj.prof, tmp.prof);                                       
    swap(obj.number, tmp.number);                                   
}
std::ostream& operator<<(std::ostream& out, const Course &rhs) 
{
    out << *(rhs.number) << " " << rhs.prof << "\n";
    out << "O: " << &rhs << "\n";                                   
    out << "P: " << &(rhs.prof) << "\n";                            
    out << "N: " << rhs.number << "\n";                             
    return out;
}

int main() 
{
    std::cout << std::endl;

    Course c1{580, "Trowbridge"};
    Course c2{575, "Sun"};

    std::cout << "C1: " << c1 << "\n";
    std::cout << "C2: " << c2 << "\n\n";

    std::cout << "CONSTRUCT C3 FROM C2: " << "\n\n";
    Course c3{c2};                                                  // call the copy constructor
    std::cout << "C3: " << c3 << "\n\n";

    std::cout << "ASSIGN C2 TO C1: " << "\n\n";
    c1 = c2;                                                        // call the assignment overload
    std::cout << "C1: " << c1 << "\n\n"; 

    std::cout << std::endl;
    return 0;
}
