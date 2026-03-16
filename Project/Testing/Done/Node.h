#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <algorithm>

struct Node {
    int data ;                                              
    Node *next;
    Node *prev;
    Node();
    Node(const int &d); 
};
#endif