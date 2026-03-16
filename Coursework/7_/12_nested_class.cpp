// S. Trowbridge 2023
#include <iostream>

class Course {                                                  // Professor is nested inside Course                        
private: 
    class Professor {                                           // Professor class is a private member of Course
    public:
        std::string name;                                       // data member public so Course can directly access it
        Professor(): name("") { }                               // default constructor
        Professor(std::string n): name(n) { }                   // one-parameter constructor
    };
    int number;                  
    Professor prof;                                             // this line must come after Profesor class code                      
public:            
    Course():number(101), prof() { }                            
    Course(int n):number(n), prof() { }                         
    Course(int n, std::string s): number(n), prof(s) {}              
    int getNumber() const { return number; }        
    void setProfName(std::string n) { prof.name = n; }          // direct access of nested class data members 
    std::string getProfName() const { return prof.name; }       // direct access of nested class data members   

    void print() const {
        std::cout << number << " " << prof.name << std::endl;   // direct access of nested class data members   
    }
}; 

int main() {
    std::cout << std::endl;

    // Professor p1;                                            // compiler error: Professor object cannot be instantiated
    Course c1;                      
    Course c2(580);
    Course c3(574, "Trowbridge");                                      

    c2.setProfName("Gayle");
    c1.print();
    c2.print();
    c3.print();

    std::cout << std::endl;
    return 0;
}
