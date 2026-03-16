// S. Trowbridge 2023
#include "Student.h"      // include required .h files

Student::Student(): name(""), id(0) { // constructor member function syntax
}

void Student::print() {     // print member function syntax
     std::cout << name << " " << id << std::endl;   
}

void print(Student &s) {    // non-member function definition
    std::cout << s.name << " " << s.id << std::endl;
}

