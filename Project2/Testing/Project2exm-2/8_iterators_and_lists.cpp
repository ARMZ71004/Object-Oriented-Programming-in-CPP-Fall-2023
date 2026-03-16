#include <iostream>
#include <list>

class Thing {
private:
    int num;
public:
    Thing(int n):num(n) {}
    friend std::ostream& operator<<(std::ostream &o, const Thing &t);   
};
std::ostream& operator<<(std::ostream &o, const Thing &t) { // << overload to print Thing objects using <<
    o << t.num;
    return o;
}

int main() {
    std::cout << std::endl;

    std::list<Thing*> list;                                 // STL dynamic array (listtor)
    std::list<Thing*>::iterator it;                         // STL iterator for a dynamic array

    // store dynamic memory  
    list.push_back( new Thing(10) );                        // store pointers to dynamic objects
    list.push_back( new Thing(15) );
    list.push_back( new Thing(20) );
    list.push_back( new Thing(25) );
    list.push_back( new Thing(30) );
    list.push_back( new Thing(35) );        

    // read/print - using ranged for loop
    for(Thing* ptr : list) {                                // list is a container of Thing pointers, ptr is a Thing pointer
        std::cout << *ptr << " ";                           // deference the Thing object, overloaded << required for the Thing object                                  
    }
    std::cout << "\n\n";

    // read/print - using iterators
    for(it = list.begin(); it != list.end(); ++it) {        // point iterator to first value, repeat until it points to last value
        std::cout << **it << " ";                           // * operator overload for iterator returns Thing pointer, * to deference the Thing pointer
    }
    std::cout << "\n\n";

    // erase data
    for(it = list.begin(); it != list.end(); ) {            
        delete *it;                                         // delete the dynamic memory variable (the data not the pointer to the data)
        it = list.erase(it);                                // delete the pointer from the data structure                                                     
    }
    list.clear();                                           // empty the list of data (only after your individually delete all dynamic memory)

    std::cout << std::endl;
    return 0;
}