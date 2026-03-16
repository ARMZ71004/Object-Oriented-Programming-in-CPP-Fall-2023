// S. Trowbridge 2023
#include <iostream>
#include <time.h>

class Course {
private:
    int *number;                                                        // dynamic data member
    int size;                                                           // automatic data member (size of the array)
    int *studentIds;                                                    // dynamic array
public:
    Course(): number( new int(0) ), size(5), studentIds(new int[5]) 
    {
        for(int i=0; i<size; ++i) {
            studentIds[i] = rand()%90+10+i;                             
        }       
    }
    Course(int n, int s) : number( new int(n)), size(s), studentIds(new int[s]) 
    {
        for(int i=0; i<size; ++i) {
            studentIds[i] = rand()%90+10+i;                             
        }
    }

    Course(const Course &rhs);                                          // copy constructor
    Course& operator=(const Course &rhs);                               // assignment operator overload
    Course(Course &&rhs) noexcept = default;                            // move constructor
    Course& operator=( Course &&rhs) noexcept = default;                // move assignment overload   
    ~Course();                                                          // destructor

    friend void swap(Course &obj, Course &tmp) noexcept;                // swap required for assignment overload   

    friend std::ostream& operator<<(std::ostream& out, const Course &c);    
};

Course::Course(const Course &rhs):                                      // copy constructor            
    number( new int( *(rhs.number) ) ),                                 
    size(rhs.size),                                                     
    studentIds( new int[rhs.size] )                                     
{
    std::copy(rhs.studentIds, rhs.studentIds + rhs.size, studentIds);   
}
Course& Course::operator=(const Course &rhs) 
{                                                                       // assignment overload
    Course tmp{rhs};                                                    
    //std::cout << tmp << std::endl;    
    swap(*this, tmp);                                                   
    //std::cout << tmp << std::endl;    
    return *this;                                                       
}
Course::~Course() 
{                                                                       // destructor
    delete [] studentIds;
}
void swap(Course &obj, Course &tmp) noexcept 
{                                                                       // swap
    using std::swap;                                                    
    swap(obj.number, tmp.number);                                       
    swap(obj.size, tmp.size);                                           
    swap(obj.studentIds, tmp.studentIds);                               
}
std::ostream& operator<<(std::ostream& out, const Course &c) 
{
    out << *c.number << "\n";                                           
    out << "O: " << &c << "\n";                                         
    out << "S: " << &(c.size) << "\n";                                       
    out << "N: " << c.number << "\n";                                   
    for(int i=0; i<c.size; ++i) {
        out << c.studentIds[i] << " ";
        out << &(c.studentIds[i]) << "\n";                              
    }
    return out;
}

int main() 
{
    std::cout << std::endl;

    srand(time(NULL));

    Course c1{580, 3};
    Course c2{575, 3};

    std::cout << "C1: " << c1 << "\n\n";
    std::cout << "C2: " << c2 << "\n\n";

    std::cout << "CONSTRUCT C3 FROM C2: " << "\n\n";
    Course c3{c2};  
    std::cout << "C3: " << c3 << "\n\n";

    std::cout << "ASSIGN C2 TO C1: " << "\n\n";
    c1 = c2;    
    std::cout << "C1: " << c1 << "\n\n";

    std::cout << std::endl;
    return 0;
}
