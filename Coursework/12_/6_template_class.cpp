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

template <typename T>                                                   // template class
class Node { 
private:
    T value;
public:
    Node(const T &v);
    T getValue() const;
    void setValue(const T &v);
    void print() const {  std::cout << value << "\n"; }             
};

template <typename T>                                                   // required for out-of-line definitions
Node<T>::Node(const T &v): value(v) {                                   // class typename outside of the class is Node<T> not Node
}

template <typename T>
T Node<T>::getValue() const {
    return value;
}

template <typename T>
void Node<T>::setValue(const T &v) {
    value = v;
}

int main() {
    std::cout << std::endl;

    char c = 'A';
    double d = 3.14;
    std::string s = "Hi";
    Obj o(1000);

    Node<int> n1(5);                                                    // primitives
    Node<char> n2(c);
    Node<double> n3(d);
    Node<std::string> n4(s);

    Node<Obj> n5(o);                                                    // object - automatic
    Node<Obj> *n6 = new Node<Obj>(o);                                   // object - dynamic
                       
    std::cout << n1.getValue() << "\n";
    std::cout << n2.getValue() << "\n";
    std::cout << n3.getValue() << "\n";
    std::cout << n4.getValue() << "\n";
    std::cout << n5.getValue().getValue() << "\n\n";   
    std::cout << n6->getValue().getValue() << "\n\n";                  // object dynamic           

    n4.print();
    n5.print(); 
    n6->print();                                                       // object dynamic

    std::cout << std::endl;
    return 0;
}
