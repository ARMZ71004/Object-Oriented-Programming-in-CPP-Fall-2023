// S. Trowbridge 2023
#ifndef COURSE_H
#define COURSE_H

#include <iostream>

class Course {                              
public:                                     
    int number;                                 

    Course();                                   // out-of-line definition (defined outside of class) 
    void setNumber(int n) {                     // inline definition (defined inside of class)
        number = n;
    }      
    int getNumber();                            // out-of-line definition (defined outside of class) 
};  

#endif