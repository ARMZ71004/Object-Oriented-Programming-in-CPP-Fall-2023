#include <iostream>
#include <vector>           // STL dynamic array container
#include <list>             // STL doubly linked list container

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

template<typename T>                        // template function for a vector
void print(std::vector<T> &vec)
{
    auto it = vec.begin();                 // auto keyword automatically derives the type from the statement (list begin returns an iterator)
    while( it != vec.end() ) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
}

template<typename T>                        // template fuction for a list
void print(std::list<T> &list)              
{
    auto it = list.begin();                 // auto keyword automatically derives the type from the statement (list begin returns an iterator)
    while( it != list.end() ) {
        std::cout << **it << " ";           // since we are using this to print lists of pointers, we need an extra * to dereference the pointer to the object
        ++it;
    }
    std::cout << "\n";
}

int main() {
    std::cout << std::endl;

    std::vector<int> ints;                      // instantiate a vector to store integers
    std::vector<Thing> things;                  // instantiate a vector of Thing objects
    std::list<int*> int_ptrs;                   // instantiate a list to integer pointers 
    std::list<Thing*> thing_ptrs;               // instantiate a list of Thing pointers

    ints.push_back(100);                        // automatic memory, store a copy of the value 100
    ints.push_back(200);
    ints.push_back(300);  
    things.push_back(Thing(400));               // automatic memory, store a copy of the Thing object
    things.push_back(Thing(500));
    things.push_back(Thing(600));    

    int_ptrs.push_back(new int(100));           // dynamic memory, store a pointer to the original integer
    int_ptrs.push_back(new int(200));
    int_ptrs.push_back(new int(300));    
    thing_ptrs.push_back(new Thing(400));       // dynamic memory, store a pointer to the original object
    thing_ptrs.push_back(new Thing(500));
    thing_ptrs.push_back(new Thing(600));

    print(ints);                                // call print for a vector
    print(things);

    std::cout << std::endl;

    print(int_ptrs);                            // call print for a list of int pointers
    print(thing_ptrs);                          // call print for a list of Thing pointers

    std::cout << std::endl;
    return 0;
}