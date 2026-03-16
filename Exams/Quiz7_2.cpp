#include <iostream>

class A {
protected:
    int *x;
public:
    A(int value) : x(new int(value)) {}
    A(const A& temp) : x(new int(*(temp.x))) {}
    A& operator=(const A& temp) {
        if (this != &temp) {
            delete x;
            x = new int(*(temp.x));
        }
        return *this;
    }
    A(A&& temp) : x(temp.x) {
        temp.x = nullptr;
    }
    A& operator=(A&& temp) {
        if (this != &temp) {
            delete x;
            x = temp.x;
            temp.x = nullptr;
        }
        return *this;
    }
    ~A() {
        delete x;
    }
};
class B : public A {
public:
    float f;
    B(int valueA, float valueB) : A(valueA), f(valueB) {}
    void print() const {
        std::cout << "A = " << *x << ", B = " << f << std::endl;
    }
    B(const B& temp) : A(temp), f(temp.f) {}
    B& operator=(const B& temp) {
        if (this != &temp) {
            A::operator=(temp);
            f = temp.f;
        }
        return *this;
    }
    B(B&& temp) : A(std::move(temp)), f(temp.f) {}
    B& operator=(B&& temp) {
        if (this != &temp) {
            A::operator=(std::move(temp));
            f = temp.f;
        }
        return *this;
    }
     ~B() {}
};

class C {
public:
    B *b;
    C(float value) : b(new B(0, value)) {}
    C(const C& temp) : b(new B(*(temp.b))) {}
    C& operator=(const C& temp) {
        if (this != &temp) {
            delete b;
            b = new B(*(temp.b));
        }
        return *this;
    }
    C(C&& temp) : b(temp.b) {
        temp.b = nullptr;
    }
    C& operator=(C&& temp) {
        if (this != &temp) {
            delete b;
            b = temp.b;
            temp.b = nullptr;
        }
        return *this;
    }
    ~C() {
        delete b;
    }
};