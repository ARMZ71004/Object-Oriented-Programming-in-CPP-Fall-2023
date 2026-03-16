// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

int main() {
    std::cout << std::endl;

    Node n1{100}; 
    Node n2{200};
    Node n3{300};   

    std::cout << n1.data << " " << n1.next << "\n";             // access data and next from node n1

    Node *ptr = &n1;                                            // ptr stores the memory address of n1
    std::cout << (*ptr).data << " " << (*ptr).next << "\n";     // dereference ptr to access n1, then access n1.data and n1.next
    std::cout << ptr->data << " " << ptr->next << "\n\n";       // arrow operator: p->x is equivalent to (*p).x    

    ptr = &n2;
    std::cout << ptr->data << " " << ptr->next << "\n";         // use ptr to read n2 data
    ptr = &n3;  
    std::cout << ptr->data << " " << ptr->next << "\n\n";       // use ptr to read n3 data

    ptr->data = 5000;                                           // use ptr to modify n3 data
    std::cout << ptr->data << " " << ptr->next << "\n";         // use ptr to read n3 data  
              
    std::cout << std::endl;
    return 0;
}


