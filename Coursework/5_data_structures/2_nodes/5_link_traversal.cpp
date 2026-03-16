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
    Node n4{400};                 
                                                                //                                          ptr
                                                                //                                          |
    n1.next = &n2;                                              // a linked list: n1 -> n2 -> n3 -> n4 -> nullptr  
    n2.next = &n3;                                          
    n3.next = &n4;                                        

    Node *ptr = &n1;                                            // ptr points to n1                                                     
    while( ptr != nullptr ) {                                   // repeat while ptr values is not nullptr
        std::cout << ptr->data << " " << ptr->next << "\n";     // deference ptr to read node data
        ptr = ptr->next;                                        // read the memory address of next, and store this in ptr (move the ptr to the next node)
    }
    std::cout << "\n";

    ptr = &n1;                                                  // reset ptr to n1                                                    
    while( ptr != nullptr) {                                    
        print(*ptr);                                            // deference ptr to access the node it points to, then send the node to the print function
        ptr = ptr->next;                                        
    }


    std::cout << std::endl;
    return 0;
}


