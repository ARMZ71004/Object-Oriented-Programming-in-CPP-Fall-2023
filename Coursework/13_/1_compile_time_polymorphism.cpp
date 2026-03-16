// S. Trowbridge 2023
#include <iostream>

void print(int i) { std::cout << i << "\n"; }
void print(std::string s) { std::cout << s << "\n"; }               // print overload (early / static binding)
 
class Example {
public:
    std::string name;
    Example(std::string n): name(n) {}
    bool operator==(const Example &e) { return name == e.name; }    // operator overload (early / static binding)
};

int main() {
    std::cout << std::endl;

    Example s("Ex1"), r("Ex2");

    print("hi");                                                    // print std::string
    print(1);                                                       // print integer

    std::cout << (1 == 2) << "\n";                                  // compare integers
    std::cout << (s == r) << "\n";                                  // compare objects

    std::cout << std::endl;
    return 0;
}
