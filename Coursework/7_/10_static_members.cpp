// S. Trowbridge 2023
#include <iostream>

class Course {
private:
    int enrollment;                                         // instance data member: 1 variable for each object
    static int numCourses;                                  // static data member: 1 variable for the entire class
    static const int maxEnrollment = 30;                    
public:
    Course():enrollment(0) {                                // instance member functions: can read/write static or instance members        
        numCourses++;                                       
    }      
    int getEnrollment() const { return enrollment; } 

    void addStudent() { 
        if(enrollment < maxEnrollment) { enrollment++; }
    }

    static int getNumCourses() {                            // static member function: can only read/write static members
        return numCourses;
    } 

    static int getMaxEnrollment() { 
        return maxEnrollment;
    }
};
int Course::numCourses = 0;                                 // non-const static members must be defined out-of-line

void print(const Course &c) {
    std::cout << c.getEnrollment() << std::endl;            // instance function MUST be called by an object
    std::cout << c.getNumCourses() << std:: endl;           // static function CAN be called by an object
    std::cout << Course::getMaxEnrollment() << std::endl;   // static function CAN be called by the class
}

int main() {
    std::cout << std::endl;

    Course c1, c2;                                          // instantiate two Course objects

    c1.addStudent();
    c1.addStudent();
    print(c1);

    std::cout << std::endl;
    return 0;
}
