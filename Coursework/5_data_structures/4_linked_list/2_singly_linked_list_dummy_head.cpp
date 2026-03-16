// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

struct List {                                               
    Node head;                                          // dummy head node                                 
    List(): head() {} 
    ~List()                                                 
    {
        Node *temp = head.next;                         // start at node after dummy head node
        Node *next;
        while(temp != nullptr) {
            next = temp;
            temp = temp->next;
            delete next;
        }
    }                               
};
void push_front(List &list, const int &d)                   
{
    Node *temp = new Node(d);                               
    temp->next = list.head.next;                                 
    list.head.next = temp;                                       
}
void push_back(List &list, const int &d)                // no edge cases with a dummy head node      
{
    Node *temp = &list.head;            
    while(temp->next != nullptr) {                          
        temp = temp->next;                                  
    }
    temp->next = new Node(d);                               
}
void print(const List &list) {                              
    Node *temp = list.head.next;                                 
    while(temp != nullptr) {                                
        std::cout << temp->data << " ";                     
        temp = temp->next;                                  
    }
    std::cout << "\n"; 
}

int main() {
    std::cout << std::endl;

    List list;  

    push_back(list, 400);                                  
    print(list);                                           
    push_front(list, 300);
    print(list);
    push_front(list, 200);
    print(list);                                               
    push_front(list, 100);
    print(list); 

    push_back(list, 500);                                   
    print(list);
    push_back(list, 600);
    print(list);    

    std::cout << std::endl;
    return 0;
}


