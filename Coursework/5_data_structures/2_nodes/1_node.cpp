// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data = 0;                                           // data
    Node *next = nullptr;                                   // link (a pointer to another node which is defaulted to nullptr)
};

int main() {
    std::cout << std::endl;

    Node n1;                                                // create a struct variables
    Node n2;                                                

    std::cout << n1.data << " " << n1.next << "\n\n";       // print the default values for a node                              
  
    n1.data = 100;                                          // assign the data variable inside each node
    n2.data = 200;                                          

    std::cout << n1.data << "\n";                           // read the data variable from each node                                   
    std::cout << n2.data << "\n";                                                                                                                    

    std::cout << std::endl;
    return 0;
}
