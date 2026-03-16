#include <iostream>
#include "functions.h"
using namespace std;

void print(Student *s, int size){
    for(int i = 0; i<size; ++i){
        print(s[i]);
    }
    cout<<endl;
}

void sort(Student *s){
    
}

int main() {         
    std::cout << std::endl;

    const int SIZE = 3;
    
    Student students[SIZE];

    students[0].name = "Sora";
    students[0].grade1 = 69.7;
    students[0].grade2 = 83.2;
    students[1].name = "Jake";
    students[1].grade1 = 93.2;
    students[1].grade2 = 72.5;
    students[2].name = "Cynthia";
    students[2].grade1 = 85.1;
    students[2].grade2 = 62.3;

    print(students, SIZE);
    sort(students);
    print(students, SIZE);

    std::cout << std::endl; 
       
    return 0;
}

