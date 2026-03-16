// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};


struct Iterator {
    Node *current;
    Iterator(Node *n): current(n) {
    }
    void next() {
        current = current->next;
    }
    bool hasNext() {
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    } 
    int& getData() {
        return current->data;
    }
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
    Iterator begin() {
        return Iterator(head);
    } 
    Iterator end() {
        return Iterator(nullptr);
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
Iterator insertAfter(List &list, Iterator itr, const int &d) // insert - insert node after itr, return it pointing to inserted node
{
    if(itr.current == nullptr || list.head == nullptr) { return itr; }   // list empty or iterator invalid: exit
    Node *temp = new Node(d);                           // create a new node
    temp->next = itr.current->next;                     // temp --> next
    itr.current->next = temp;                           // current --> temp --> next
    return Iterator(temp);
}
Iterator eraseAfter(List &list, Iterator itr)           // erase node after itr
{
    if(itr.current == nullptr || list.head == nullptr) { return itr; }  // list empty or iterator invalid: exit
    Node *temp = itr.current->next;                     // temp points to node after current
    itr.current->next = temp->next;                     // current --> node after temp
    delete temp;                                        // erase temp
    return itr;                                         // return an iterator to the current position     
}
void duplicate(List &a, List &b)
{
    Iterator itr = a.begin();
    while( itr.hasNext() ) {
        push_back(b, itr.getData());    
        itr.next();  
    }   
}
void print(List &list) {                              
    for(Iterator itr=list.begin(); itr.hasNext(); itr.next()) {
        std::cout << itr.getData() << " ";
    }  
    std::cout << "\n";
}
Iterator find(List &list, int d) 
{
    Iterator itr = list.begin();
    while( itr.hasNext() ) {
        if( itr.getData() == d ) { return itr; }
        itr.next();
    }   
    return Iterator(nullptr);     
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

    Iterator itr = list.begin();

    std::cout << "\nFIND/INSERT AFTER\n";
    itr = find(list, 200);
    insertAfter(list, itr, 300);                    // insert 300 after 200
    itr = find(list, 400);
    insertAfter(list, itr, 500);                    // insert 500 after 400   
    itr = find(list, 800);
    insertAfter(list, itr, 900);                    // insert 900 after 800 (edge case)    
    print(list);

    std::cout << "\nFIND/ERASE AFTER\n";    
    itr = find(list, 300);
    eraseAfter(list, itr);                          // erase node after 300
    itr = find(list, 800);
    eraseAfter(list, itr);                          // erase node after 800 (edge case)    
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