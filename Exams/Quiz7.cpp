#include <iostream>

template <typename T>
class Thing {
private:
    T val;
public:
    Thing(const T &v);
    T getVal() const;
    void print() const;
};

template <typename T>
Thing<T>::Thing(const T &v): val(v) {}

template <typename T>
T Thing<T>::getVal() const { 
    return val; 
}
template <typename T>
void Thing<T>::print() const { 
    std::cout << val << std::endl; 
}

int main() {
    std::cout << std::endl;
    Thing<int> *t = new Thing(5);
    t->print();
    std::cout << std::endl;
    return 0;
}