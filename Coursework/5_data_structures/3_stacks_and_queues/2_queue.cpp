// S. Trowbridge 2023
#include <iostream>

struct Node {
    int data ;                                              
    Node *next;   
    Node(): data(0), next(nullptr) {}                      
    Node(const int &d): data(d), next(nullptr) {}                                
};

struct Queue {
    Node *front;
    Node *back;    
    Queue(): front(nullptr), back(nullptr) {}
    ~Queue() 
    {
        Node *current = front;
        Node *next;
        while(current != nullptr) {
            next = current;
            current = current->next;
            delete next;
        }
    }
};
          
void push(Queue &queue, const int &d)
{
    Node *temp = new Node(d);
    if(queue.front == nullptr) {                            // queue is empty: point front and back to temp
        queue.front = temp;                                 
        queue.back = temp;
    } else {
        queue.back->next = temp;                            // back --> temp (back becomes 2nd to last node)
        queue.back = temp;                                  // temp becomes the new back
    }
}
void pop(Queue &queue) 
{
    if(queue.front == nullptr) { return; }                  // queue is empty: nothing to pop, exit
    Node *temp = queue.front;                               // temp points to front
    queue.front = queue.front->next;                        // front points to the 2nd node
    if(temp->next == nullptr) { queue.back = nullptr; }
    delete temp;                                            // delete temp
}
void print(const Queue &queue) 
{
    Node *temp = queue.front;                               // temp points to front
    while(temp != nullptr) {                                // repeat until temp points to nullptr
        std::cout << temp->data << " ";                     // print temp node data
        temp = temp->next;                                  // move temp forward through the queue
    }
    std::cout << std::endl;
}  
int main() {
    std::cout << std::endl;

    Queue queue;

    push(queue, 10);
    push(queue, 20);
    push(queue, 30);
    push(queue, 40);
    push(queue, 50);
    print(queue);                

    pop(queue);
    pop(queue);
    print(queue);

    std::cout << std::endl;    
    return 0;
}