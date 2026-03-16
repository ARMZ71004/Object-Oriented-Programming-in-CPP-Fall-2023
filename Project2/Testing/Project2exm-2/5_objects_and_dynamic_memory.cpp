#include <iostream>

class Thing {
private:
    int num;
public:
    Thing(int n):num(n) {}
    friend std::ostream& operator<<(std::ostream &o, const Thing &t);   
};
std::ostream& operator<<(std::ostream &o, const Thing &t) {  // << overload to print thing objects
    o << t.num;
    return o;
}

int main() {
    std::cout << std::endl;

    const int CAPACITY = 10;
    Thing* things[CAPACITY];
    int size = 5;

    things[0] = new Thing(10);              // store dynamic objects
    things[1] = new Thing(20);
    things[2] = new Thing(30);
    things[3] = new Thing(40);            
    things[4] = new Thing(50);   

    for(int i=0; i<size; ++i) {
        std::cout << *(things[i]) << " ";   // derefence the stored pointer to access the thing object 
                                            // << must be overloaded to print the thing object
    }      

    std::cout << std::endl;
    return 0;
}