// S. Trowbridge 2023
#include <iostream>
#include "Student.h"

int main() {                    // this is the only file with a main function to run the program
    std::cout << std::endl;

    const int SIZE = 3;
    Student students[5];        // create an array of student variables

    students[0].name = "John";  // store data into the student variables in the array
    students[0].id = 14141414;
    students[1].name = "Kim";
    students[1].id = 25252525;
    students[2].name = "Ara";
    students[2].id = 53246534;

    for(int i=0; i<SIZE; ++i) { // iterate through the array to print each student variable
        print(students[i]);         // call non-member print
        //students[i].print();      // call the member print
    }

    std::cout << std::endl;    
    return 0;
}

