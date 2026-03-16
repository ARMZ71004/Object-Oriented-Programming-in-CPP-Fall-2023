#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <algorithm>
#include "Node.h"
#include "Iterator.h"
#include "Profession.h"

struct List {                                               
    Node *head;                                             
    Node *tail;
    List();
    ~List();
    Iterator begin();
    Iterator end(); 
    Iterator rbegin();
    Iterator rend();
    void push_front(List &list, const Profession &d);
    void push_back(List &list, const Profession &d);
    void pop_front(List &list);
    void pop_back(List &list);
    Iterator insert(List &list, Iterator itr, const Profession &d);
    Iterator erase(List &list, Iterator itr); 
    void duplicate(List &a, List &b);
    void print(List &list);
    void printRev(List &list);
    Iterator find(List &list, int d); 
};

#endif