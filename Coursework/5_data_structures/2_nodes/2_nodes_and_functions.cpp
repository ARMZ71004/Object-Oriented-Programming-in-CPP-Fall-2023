// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data;                                              
    Node *next; 
    Node(): data(0), next(nullptr) {}                           // default constructor function with an initialization list (assign default values)
    Node(const int &d): data(d), next(nullptr) {}               // parameterized constructor function with an initialization list (assign specific values)
};

void print(const Node &n) {                                     // a function to print node data and next pointer values
    std::cout << n.data << " " << n.next << "\n";
}

int main() {
    std::cout << std::endl;

    Node n1;                                                    // initialize nodes with the default constructor
    Node n2{200};                                               // initialize nodes with the parameterized constructor                                                 

    print(n1);                                                 
    print(n2);                                                    

    std::cout << std::endl;
    return 0;
}
