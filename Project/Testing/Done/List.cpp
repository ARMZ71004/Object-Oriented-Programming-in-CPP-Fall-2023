#include "List.h"
#include "Node.h"
                                              
Node *head;                                             
Node *tail;
List::List(): head(nullptr), tail(nullptr) {}
List::~List()
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
/*Iterator begin() {
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
}    */