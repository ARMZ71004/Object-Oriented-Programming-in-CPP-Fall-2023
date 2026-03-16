// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;
    Node *prev; 
    Node(): data(0), next(nullptr), prev(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr), prev(nullptr) {}                                
};

struct Iterator {
    Node *current;
    Iterator(Node *n): current(n) {
    }
    void next() {
        current = current->next;
    }
    void prev() {
        current = current->prev;
    }
    bool hasNext() {
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    }
    bool hasPrev() {
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
    Iterator begin() {
        return Iterator(head);
    } 
    Iterator end() {
        return Iterator(nullptr);
    }
    Iterator rbegin() {
        return Iterator(tail);
    }                    
    Iterator rend() {
        return Iterator(nullptr);
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
Iterator insert(List &list, Iterator itr, const int &d)     // insert - insert node before itr, return it pointing to inserted node
{
    if(itr.current == nullptr) { return itr; }              // node invalid: exit
    if(list.head == nullptr || itr.current == list.head) {  // list empty or iterator points to head: call push_front, return iterator to head
        push_front(list, d);
        return list.begin();
    }
    Node *temp = new Node(d);                               // create a new node
    temp->next = itr.current;                               // temp --> current
    temp->prev = itr.current->prev;                         // previous <-- temp --> current
    itr.current->prev->next = temp;                         // previous <--> temp --> current
    itr.current->prev = temp;                               // previous <--> temp <--> current
    return Iterator(temp);
}
Iterator erase(List &list, Iterator itr)                    // erase node before iterator 
{
    if(itr.current == nullptr) { return itr; }              // node invalid: exit
    if(list.head == nullptr || itr.current == list.head ) { return itr; } // list empty or iterator points to head: nothing to erase, exit
    if(list.head == itr.current->prev) {                    // iterator points to 2nd node: pop_front
        pop_front(list);
        return list.begin();                                // return an iterator to the new head node
    }
    Node *temp = itr.current->prev;                         // temp points to node before iterator
    itr.current->prev = temp->prev;                         // node before temp <-- iterator
    temp->prev->next = itr.current;                         // node before temp <--> iterator
    delete temp;                                            // erase temp
    return itr;                                             // return an iterator to the current position 
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
void printRev(List &list) { 
    Iterator itr = list.rbegin();
    while(itr.hasPrev()) {
        std::cout << itr.getData() << " ";    
        itr.prev();  
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

    Iterator itr = list.begin();                              // point an iterator to the list

    std::cout << "\nFIND/INSERT\n";
    itr = find(list, 200);
    insert(list, itr, 100);                                   // insert 100 before 200 (edge case)
    itr = find(list, 400);
    insert(list, itr, 300);                                   // insert 300 before 400   
    itr = find(list, 800);
    insert(list, itr, 700);                                   // insert 700 before 800     
    print(list);
    printRev(list);    

    std::cout << "\nFIND/ERASE\n";    
    itr = find(list, 200);
    erase(list, itr);                                         // erase 100, the node before 200 (edge case)
    itr = find(list, 800);
    erase(list, itr);                                         // erase 700, the node before 800     
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



// add the list code to list files bring back drive code in main and test .get profession.h and cpp . update node to include profession. update list to include profession. update read function to add push back function to store profession object in the data structure