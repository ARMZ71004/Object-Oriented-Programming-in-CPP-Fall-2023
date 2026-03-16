// S. Trowbridge 2023
#include "Course.h"

Course::Course() {              // classname and scope resolution operator (::) required for out-of-line definition (Classname::)                                 
    number = 101;
}
int Course::getNumber() {       // classname and scope resolution operator (::) required for out-of-line definition (Classname::)
    return number; 
}
