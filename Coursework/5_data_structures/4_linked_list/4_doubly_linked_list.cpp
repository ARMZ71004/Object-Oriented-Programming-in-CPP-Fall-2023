// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;
    Node *prev; 
    Node(): data(0), next(nullptr), prev(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr), prev(nullptr) {}                                
};

struct List {                                               
    Node *head;                                             
    Node *tail;
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
    Node *temp = new Node(d);                               // nullptr <-- temp --> nullptr
    if(list.head == nullptr) {                              // list empty: 
       list.tail = temp;                                    //      temp becomes new tail
    } else {
        temp->next = list.head;                             //      nullptr <-- temp --> head 
        list.head->prev = temp;                             //      nullptr <-- temp <--> head    
    }             
    list.head = temp;                                       // temp becomes new head
}
void push_back(List &list, const int &d)                    
{
    if(list.head == nullptr) {                              // list empty: push_front
        push_front(list, d);
        return;
    }
    Node *temp = new Node(d);                               // nullptr <-- temp --> nullptr                               
    list.tail->next = temp;                                 // tail --> temp --> nullptr                      
    temp->prev = list.tail;                                 // tail <--> temp --> nullptr      
    list.tail = temp;                                       // temp becomes new tail
}
//              
//              head        tail   
// nullptr   <- [] <->      [] -> nullptr
//
//
//
void pop_front(List &list) {
    if(list.head == nullptr) { return; }                    // list empty: nothing to pop, exit
    Node *temp = list.head;                                 // temp points to head
    list.head = list.head->next;                            // head -> 2nd node or nullptr
    delete temp;                                            // delete original head
    if(list.head != nullptr) {                              // list has data: 
        list.head->prev = nullptr;                          //      nullptr <- head
    } else {                                                // list is empty:
        list.tail = nullptr;                                //      tail-> nullptr 
    }
}
void pop_back(List &list) {
    if(list.tail == nullptr) { return; }                    // list empty: nothing to pop, exit
    if(list.tail == list.head) {                            // list has one node: pop_front
        pop_front(list);
        return;
    }
    Node *temp = list.tail;                                 // temp points to tail
    list.tail = list.tail->prev;                            // tail points to 2nd to last node 
    list.tail->next = nullptr;                              // tail --> nullptr (reset tail)  
    delete temp;                                            // delete temp
}
void insert(List &list, Node *n, const int &d)              // insert before n
{
    if(n == nullptr) { return; }                            // n invalid: exit
    if(list.head == nullptr || list.head == n) {            // list empty or n is head: call push_front
        push_front(list, d);
        return;
    }
    Node *temp = new Node(d);                               // nullptr <-- temp --> nullptr
    temp->prev = n->prev;                                   // previous <-- temp --> nullptr
    temp->next = n;                                         // previous <-- temp --> n
    n->prev->next = temp;                                   // previous <--> temp --> n
    n->prev = temp;                                         // previous <--> temp <--> n
}
void erase(List &list, Node *n)                             // erase before n
{
    if(n == nullptr) { return; }                            // node invalid: exit
    if(list.head == nullptr || list.head == n ) { return; } // list empty or n is head: nothing to erase, exit
    if(list.head == n->prev) {                              // n is 2nd node: pop_front
        pop_front(list);
        return;
    }
    Node *temp = n->prev;                                   // temp points to node before n
    n->prev = temp->prev;                                   // node before temp <-- n
    temp->prev->next = n;                                   // node before temp --> n
    delete temp;                                            // erase temp
}
void duplicate(const List &a, List &b)
{
    Node *temp = a.head;  
    while(temp != nullptr) {
        push_back(b, temp->data);                           
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
void printRev(const List &list) {                              
    Node *temp = list.tail;                                 // temp points to tail                         
    while(temp != nullptr) {                                 
        std::cout << temp->data << " ";                      
        temp = temp->prev;                                  // move temp backwards through list             
    } 
    std::cout << "\n";     
}
Node* find(const List &list, int d) {
    Node *temp = list.head;                                  
    while(temp != nullptr) {                                 
        if(temp->data == d) { return temp; }                     
        temp = temp->next;                                    
    }
    return nullptr;   
    std::cout << "\n";         
}


int main() {
    std::cout << std::endl;

    List list; 

    std::cout << "PUSH\n";
    push_front(list, 400);
    push_front(list, 200);  
    push_front(list, 100);
    push_back(list, 600);  
    push_back(list, 800); 
    push_back(list,1000);
    push_back(list,1200);                                                                                                                  
    print(list); 
    printRev(list);

    std::cout << "\nPOP\n";
    pop_front(list);
    pop_back(list);
    pop_back(list);
    print(list);
    printRev(list);    

    std::cout << "\nFIND/INSERT\n";
    Node *n = find(list, 200);
    insert(list, n, 100);                                   // insert 100 before 200 (edge case)
    n = find(list, 400);
    insert(list, n, 300);                                   // insert 300 before 400   
    n = find(list, 800);
    insert(list, n, 700);                                   // insert 700 before 800     
    print(list);
    printRev(list);    

    std::cout << "\nFIND/ERASE\n";    
    n = find(list, 200);
    erase(list, n);                                         // erase node before 200 (edge case)
    n = find(list, 800);
    erase(list, n);                                         // erase node before 800     
    print(list);
    printRev(list);        

    std::cout << "\nCOPY\n"; 
    List list_copy;
    duplicate(list, list_copy);                             // duplicate list without sharing memory
    print(list);
    print(list_copy);                               

    std::cout << "\nMEMORY INDEPENDENCE\n";  
    list.~List();                                           // erase list
    print(list_copy);                                       // print copy

    std::cout << std::endl;
    return 0;
}



