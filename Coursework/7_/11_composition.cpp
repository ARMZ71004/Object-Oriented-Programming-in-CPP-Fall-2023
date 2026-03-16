// S. Trowbridge 2023
#include <iostream>

class Professor {
private:
    std::string name;
public:
    Professor(): name("staff") { }                              // default constructor
    Professor(std::string n): name(n) { }                       // one-parameter constructor
    void setName(std::string n) { name = n; }
    std::string getName() const { return name; }
};

class Course {                                                  // Course has-a Professor (Class Composition)                          
private:    
    int number;                  
    Professor prof;                                             // Course object contains a Professor object                         
public:            
    Course():number(101), prof() { }                            // call default Professor constructor
    Course(int n):number(n), prof() { }                         // call default Professor constructor
    Course(int n, std::string s): number(n), prof(s) {}         // call one-parameter Professor constructor
    int getNumber() const { return number; }        
    void setProfName(std::string n) { prof.setName(n); }        // call Professor mutator
    std::string getProfName() const { return prof.getName(); }  // call Professor accessor
}; 

void print(const Course &c) {
    std::cout << c.getNumber() << " " << c.getProfName() << std::endl;
}

int main() {
    std::cout << std::endl;

    Professor p1("Sun");
    Course c1;                      
    Course c2(580);
    Course c3(574, "Trowbridge");                                   

    std::cout << c2.getProfName() << std::endl;
    c2.setProfName("Gayle");

    print(c1);
    print(c2);
    print(c3);

    std::cout << std::endl;
    return 0;
}
