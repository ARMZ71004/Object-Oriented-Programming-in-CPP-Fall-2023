#include "functions.h"

float average(Student &s){
return (s.grade1 + s.grade2) / 2;
}

void print(Student &s){
cout<<s.name<<" "<<average(s)<<endl;
}
