#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

struct Student{
    string name;
    float grade1;
    float grade2;
};

void print(Student &s);

float average(Student &s);

#endif