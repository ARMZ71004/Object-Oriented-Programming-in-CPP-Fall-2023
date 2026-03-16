// S. Trowbridge 2023
#ifndef STUDENT_H         // preprocessor directives
#define STUDENT_H

#include <iostream>         // iostream is required for string and the print function

struct Student {            // struct declaration
    std::string name;
    int id;
    Student();              // constructor, member function
    void print();           // print member function declaration - call with s1.print() if s1 is a Student object
};

void print(Student &s);     // print non-member function declaration - call with print(s1) if s1 is a Student object

#endif

