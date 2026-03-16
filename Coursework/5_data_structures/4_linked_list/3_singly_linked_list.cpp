// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

struct List {                                               
    Node *head;                                             
    Node *tail;                                         // tail points to the last node in the list
    List(): head(nullptr), tail(nullptr) {}
    ~List()
    {
        Node *temp = head;
        Node *next;
        while(temp != nullptr) {
            next = temp;
            temp = temp->next;
            delete next;
        }
        head = tail = nullptr;
    }                 
};

void push_front(List &list, const int &d)                   
{
    Node *temp = new Node(d);                           // temp --> nullptr                                    
    temp->next = list.head;                             // temp --> head/nullptr         
    list.head = temp;                                   // temp becomes new head
    if(list.tail == nullptr) { list.tail = temp; }      // list empty: temp becomes new tail
}
void push_back(List &list, const int &d)                    
{
    if(list.head == nullptr) {                          // list empty: push_front
        push_front(list, d);
        return;
    }
    Node *temp = new Node(d);                           // temp --> nullptr   
    list.tail->next = temp;                             // tail --> temp --> nullptr                      
    list.tail = temp;                                   // temp becomes new tail
}
void pop_front(List &list) 
{
    if(list.head == nullptr) { return; }                // list empty: nothing to pop, exit
    Node *temp = list.head;                             // temp points to head
    list.head = list.head->next;                        // head points to 2nd node or nullptr
    delete temp;                                        // delete original head
    if(list.head == nullptr) { list.tail = nullptr; }   // empty list: reset tail to nullptr
}
void insertAfter(List &list, Node *n, const int &d) 
{
    if(n == nullptr) { return; }                        // n invalid: exit
    if(list.head == nullptr) {                          // list empty: push_front
        push_front(list, d);
        return;
    }
    Node *temp = new Node(d);                           // temp --> nullptr
    temp->next = n->next;                               // temp --> next/nullptr
    n->next = temp;                                     // n --> temp --> next
    if(list.tail == n) { list.tail = temp; }            // n was tail: temp becomes new tail
}
void eraseAfter(List &list, Node *n)
{
    if(list.head == nullptr) { return; }                // n invalid: exit
    if(list.tail == n) { return; }                      // n is tail: nothing to erase, exit        
    if(list.tail == n->next) { list.tail = n; }         // next is tail: n becomes new tail
    Node *temp = n->next;                               // n --> temp --> nextnext/nullptr
    n->next = temp->next;                               // n --> nextnext/nullptr
    delete temp;
}
void duplicate(const List &a, List &b)
{
    Node *temp = a.head;  
    while(temp != nullptr) {
        push_back(b, temp->data);                    // use push_back to create nodes in new list that are copy of the old list
        temp = temp->next;
    }    
}
void print(const List &list) {                              
    Node *temp = list.head;                                                      
    while(temp != nullptr) {                               
        std::cout << temp->data << " ";                 
        temp = temp->next;                              
    }
    std::cout << "\n";
}
Node* find(const List &list, int d) {
    Node *temp = list.head;                                                                   
    while(temp != nullptr) {                                                    
        if(temp->data == d) { return temp; }            // data found: return pointer to temp node        
        temp = temp->next;                              
    }
    return nullptr;                                     // data not found: return nullptr
}

int main() {
    std::cout << std::endl;

    List list; 

    std::cout << "PUSH\n";
    push_front(list, 200);
    push_front(list, 100);
    push_back(list, 400);     
    push_back(list, 600);
    push_back(list, 800);                                                                                                                   
    print(list); 

    std::cout << "\nPOP\n";
    pop_front(list);
    print(list);

    std::cout << "\nFIND/INSERT AFTER\n";
    Node *n = find(list, 200);
    insertAfter(list, n, 300);                      // insert 300 after 200
    n = find(list, 400);
    insertAfter(list, n, 500);                      // insert 500 after 400   
    n = find(list, 800);
    insertAfter(list, n, 900);                      // insert 900 after 800 (edge case)    
    print(list);

    std::cout << "\nFIND/ERASE AFTER\n";    
    n = find(list, 300);
    eraseAfter(list, n);                            // erase node after 300
    n = find(list, 800);
    eraseAfter(list, n);                            // erase node after 800 (edge case)    
    print(list);

    std::cout << "\nCOPY\n"; 
    List list_copy;
    duplicate(list, list_copy);                     // duplicate list without sharing memory
    print(list);
    print(list_copy);                               

    std::cout << "\nMEMORY INDEPENDENCE\n";  
    list.~List();                                   // erase list
    print(list_copy);                               // print copy

    std::cout << std::endl;
    return 0;
}