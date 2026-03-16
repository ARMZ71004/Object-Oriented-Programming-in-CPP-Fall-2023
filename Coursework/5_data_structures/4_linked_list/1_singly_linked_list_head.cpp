// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

struct List {                                           // struct for creating list variables
    Node *head;                                         // ptr to the first node in the list
    List(): head(nullptr) {}                            // constructor to create an empty list
    ~List()                                             // destructor to dellocate list memory
    {
        Node *temp = head;                              // temp points to head
        Node *next;                                      
        while(temp != nullptr) {                        // iterate through the list
            next = temp;                                // next points to temp
            temp = temp->next;                          // temp points to the next node (advance temp forward)
            delete next;                                // delete each node in the list
        }
        head = nullptr;                                 // reset head to avoid dangling pointer
    }
};
void push_front(List &list, const int &d)               // prepend node (add node to start of list)
{
    Node *temp = new Node(d);                           // temp --> nullptr
    temp->next = list.head;                             // temp --> head (link temp next to head)
    list.head = temp;                                   // temp becomes the new head
}
void push_back(List &list, const int &d)                // append node (add node to end of list)
{
    if(list.head == nullptr) {                          // list empty: push_front
        push_front(list, d);
        return ;
    }
    Node *temp = list.head;                             // temp points to head
    while(temp->next != nullptr) {                      // repeat until temp is the last node
        temp = temp->next;                              
    }
    temp->next = new Node(d);                           // temp --> new node --> nullptr (new node becomes the end of the list)
}
void print(const List &list) {                              
    Node *temp = list.head;                                                       
    while(temp != nullptr) {                            
        std::cout << temp->data << " ";                 
        temp = temp->next;                              
    }
    std::cout << "\n";
}

int main() {
    std::cout << std::endl;

    List list;                                              // create a list 
                         
    push_front(list, 400);                                  // add node to front of list
    print(list);                                           
    push_front(list, 300);
    print(list);
    push_front(list, 200);
    print(list);                                               
    push_front(list, 100);
    print(list); 

    push_back(list, 500);                                   // add node to back of list                               
    print(list);
    push_back(list, 600);
    print(list);    

    std::cout << std::endl;
    return 0;
}


