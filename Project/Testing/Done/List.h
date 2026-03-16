#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <algorithm>
#include "Node.h"

struct List {                                               
    Node *head;                                             
    Node *tail;
    List();
    ~List();
};

#endif