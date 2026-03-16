// S. Trowbridge 2023
#include <iostream>

class Thing {  
    private:
        int num;
    public:
        Thing(): num(0) {}
        Thing(int n): num(n) {}
        void setData(int n) { num = n; }
        int getData() const { return num; }
        friend std::ostream& operator<<(std::ostream &out, const Thing &t);
};
std::ostream& operator<<(std::ostream &out, const Thing &t) // overload << to print Thing objects
{
    out << t.num;
    return out;
}

struct Node {
    Thing data;                                              
    Node *next;   
    Node(): data(), next(nullptr) {}                      
    Node(const Thing &t): data(t), next(nullptr) {}                                
};

struct Iterator {
    Node *current;
    Iterator(Node *n): current(n) {
    }
    Iterator& operator++() {                                // overload prefix ++ - increment iterator to next node
        current = current->next;
        return *this;
    } 
    Iterator operator++(int) {                              // overload postfix ++ - increment iterator to next node
        Iterator temp{*this};
        current = current->next;
        return temp;
    }
    bool operator==(Iterator const &rhs) const {            // overload equivalence - do two iterators point to the same node
        return current == rhs.current;
    }        
    bool operator!=(Iterator const &rhs) const {            // overload inequivalence - do two iterators point to different nodes
        return current != rhs.current;
    }
    Thing& operator*() const {                              // overload star - return a reference to the data inside the current node
        return current->data;
    }
    Thing* operator->() const {                             // overload arrow - return the memory address of the data inside the current node
        return &(current->data);
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
    Iterator begin() {                                  // return an iterator that points to head
        return Iterator(head);
    } 
    Iterator end() {                                    // return an iterator which points to just past tail (nullptr)
        return Iterator(nullptr);
    }                  
};
void push_front(List &list, const Thing &t)                   
{
    Node *temp = new Node(t);                                                             
    temp->next = list.head;                                      
    list.head = temp;                                   
    if(list.tail == nullptr) { list.tail = temp; }      
}
void push_back(List &list, const Thing &t)                    
{
    if(list.head == nullptr) {                          
        push_front(list, t);
        return;
    }
    Node *temp = new Node(t);                            
    list.tail->next = temp;                                                 
    list.tail = temp;                                   
}

int main() {
    std::cout << std::endl;

    List list; 

    push_front(list, Thing(200));
    push_front(list, Thing(100));
    push_back(list, Thing(400));     
    push_back(list, Thing(600));
    push_back(list, Thing(800)); 

    Iterator it = list.begin();                 // point an iterator to the first node of the list
    while( it != list.end()) {                  // iterate until we reach the last node of the list
        std::cout << *it << " ";                // access the node and return the Thing object (the << overload of Thing then prints the value of num)
        ++it;                                   // advance the iterator to point to the next node in the list
    }
    std::cout << std::endl;

    it = list.begin();                          // point iterator back to the first node in the list
    it->setData(50000);                         // use the arrow operator to write the value of num inside a Thing, inside a Node
    std::cout << it->getData() << std::endl;    // use the arrow operator to read the value of num inside a Thing, inside a Node

    std::cout << std::endl;
    return 0;
}