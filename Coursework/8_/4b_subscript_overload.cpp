// S. Trowbridge 2023
#include <iostream>

class Name {
private:
    std::string first;
    std::string last;    
public:
    Name(): Name("","") { }
    Name(std::string f, std::string l): first(f), last(l) { }
    void output() const { std::cout << first << " " << last << "\n"; }

    std::string& operator[](int index) {    
        if(index < 0 || index > 1) { throw std::out_of_range ("index is out of range"); }   
        if(index == 0)                      // index can refer to a specific variable, 0 for first, 1 for last
            return first;
        else
            return last;
    }
    const std::string& operator[](int index) const {
        if(index < 0 || index > 1) { throw std::out_of_range ("index is out of range"); }  
        if(index == 0)
            return first;
        else
            return last;
    }
};

int main() {
    std::cout << std::endl;

    Name n{"John", "Smith"};
    n.output();
    try {
        std::cout << n[0] << "\n";
        std::cout << n[1] << "\n\n";
        n[0] = "Jane";
        n[1] = "Doe";
        std::cout << n[0] << "\n";
        std::cout << n[1] << "\n\n";
    } catch(const std::out_of_range e) {
        std::cerr << e.what() << std::endl;
    }

    const Name n2{"Jane", "Doe"};
    try {
        std::cout << n2[0] << "\n";
        std::cout << n2[1] << "\n\n";
        //n2[0] = "Sara";                       // compiler error: object is read only
    } catch(const std::out_of_range e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
