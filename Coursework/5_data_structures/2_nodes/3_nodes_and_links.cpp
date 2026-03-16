// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

void print(const Node &n) {
    std::cout << n.data << " " << n.next << "\n";
}

int main() {
    std::cout << std::endl;

    Node n1{100};                                               
    Node n2{200};                                           
    Node n3{300};                                                   

    print(n1);                                              // default value for next is nullptr which prints out as 0x0
    print(n2);
    print(n3);
    std::cout << "\n";          
                                                            // linked nodes: n1 -> n2 -> n3 -> nullptr
    n1.next = &n2;                                          // link n1 to n2 by storing the memory address of n2 in n1.next                                      
    n2.next = &n3;                                          // link n2 to n3 by storing the memory address of n3 in n2.next                                                                                  
    
    std::cout << n1.next << " " << &n2 << "\n";             // compare value of next with the memory address of the variable it points to
    std::cout << n2.next << " " << &n3 << "\n";                          
    std::cout << n3.next << "\n";            

    std::cout << std::endl;
    return 0;
}


