// S. Trowbridge 2023
#include <iostream>

class Obj {                                                             // generic obj to store some data              
private:
    int num;
public:
    Obj()=default;
    Obj(int n): num(n) { }
    int getValue() const { return num; }
    friend std::ostream& operator<<(std::ostream &out, const Obj &o);
};
std::ostream& operator<<(std::ostream &out, const Obj &o) {
    out << o.num;
    return out;
}

template <typename T>                                                   // indicates this is a template class
class Node { 
private:
    T value;
public:
    Node(const T &v);                                                   
    T getValue() const;                                                 
    void setValue(const T &v);
    void print() const {  std::cout << value << "\n"; }             
};
template <typename T>                                                   
Node<T>::Node(const T &v): value(v) {                                   
}
template <typename T>
T Node<T>::getValue() const {
    return value;
}
template <typename T>
void Node<T>::setValue(const T &v) {
    value = v;
}

template <typename T>
class Node<T*> {                                                        // partial specialization to store pointers
private:
    T *value;                                                           // data is a pointer type
public:
    Node(T *v);                                                         // store a pointer
    T* getValue() const;                                                // return a pointer
    void setValue(T *v);                                                // store a pointer
    void print() const {  std::cout << *value << "\n"; }               // deference           
};
template <typename T>                                                   
Node<T*>::Node(T *v): value(v) {                                       
}
template <typename T>
T* Node<T*>::getValue() const {
    return value;
}
template <typename T>
void Node<T*>::setValue(T *v) {
    value = v;
}


int main() {
    std::cout << std::endl;

    Obj o(1000);

    Node<Obj> n(o);                                                     // store a reference to the object
    std::cout << n.getValue().getValue() << "\n";    
    n.print();

    Node<Obj*> p(&o);                                                    // store a pointer to an object
    std::cout << p.getValue()->getValue() << "\n";        
    p.print();

    Node<Obj*> *p2 = new Node<Obj*>(&o);                                // store a dynamic node object of an obj pointer
    std::cout << p2->getValue()->getValue() << "\n";        
    p2->print();

    std::cout << std::endl;
    return 0;
}
