#include <iostream>
#include <vector>

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

    std::vector<Thing*> vec;                                // STL dynamic array (vector)
    std::vector<Thing*>::iterator it;                       // STL iterator for a dynamic array

    // store dynamic memory  
    vec.push_back( new Thing(10) );                         // store pointers to dynamic objects
    vec.push_back( new Thing(15) );
    vec.push_back( new Thing(20) );
    vec.push_back( new Thing(25) );
    vec.push_back( new Thing(30) );
    vec.push_back( new Thing(35) );        

    // read/print - using ranged for loop
    for(Thing* ptr : vec) {                                 // vec is a container of Thing pointers, ptr is a Thing pointer
        std::cout << *ptr << " ";                           // deference the Thing object, overloaded << required for the Thing object                                  
    }
    std::cout << "\n\n";

    // read/print - using iterators
    for(it = vec.begin(); it != vec.end(); ++it) {          // point iterator to first value, repeat until it points to last value
        std::cout << **it << " ";                           // * operator overload for iterator returns Thing pointer, * to deference the Thing pointer
    }
    std::cout << "\n\n";

    // read/print - using indexes
    for(int i=0; i <vec.size(); ++i) {                      // use indicies just like regular array
        std::cout << *(vec[i]) << " ";                      // [] operator works for reading (dont use for writing), * to deference the Thing pointer
    }
    std::cout << "\n\n";    

    // erase data
    for(it = vec.begin(); it != vec.end();  ) {
        it = vec.erase(it);                                 // STL erase function returns an incremented iterator (use this to avoid invalidation)                                                        
    }
    vec.clear();                                            // empty the vector of data (only after your individually delete all dynamic memory)

    std::cout << std::endl;
    return 0;
}