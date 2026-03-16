// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

struct Stack {
    Node *topNode;
    Stack(): topNode(nullptr) {}                            // constructor - called whenever we initialize an object (object is created)
    ~Stack()                                                // destructor - called whenever an object is to be deleted
    {
        Node *current = topNode;
        Node *next;
        while(current != nullptr) {
            next = current;
            current = current->next;
            delete next;
        }
    }
};

void push(Stack &stack, const int &d)
{
    Node *temp = new Node(d);                               // temp is the new node
    temp->next = stack.topNode;                             // temp --> top/nullptr
    stack.topNode = temp;                                   // temp is the new topNode
}
void pop(Stack &stack) 
{
    if( stack.topNode == nullptr ) { return; }              // stack is empty: nothing to pop, exit
    Node *temp = stack.topNode;                             // temp is the topNode
    stack.topNode = stack.topNode->next;                    // topNode set to 2nd node or nullptr
    delete temp;                                            // delete temp
}
void print(const Stack &stack) 
{
    Node *temp = stack.topNode;                             // temp points to topNode
    while(temp != nullptr) {                                // repeat until temp points to nullptr
        std::cout << temp->data << " ";                     // print temp node data
        temp = temp->next;                                  // move temp forward through the stack
    }
    std::cout << std::endl;
}  
int main() {
    std::cout << std::endl;

    Stack stack;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    print(stack);                

    pop(stack);
    pop(stack);
    print(stack);

    std::cout << std::endl;    
    return 0;
}
