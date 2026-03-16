#include <iostream>
#include <sstream>
#include <fstream>
#include "Node.h"
#include "List.h"
#include "Iterator.h"

void read(std::string file, List &list){
    std::ifstream Files;
    std::string cline, token;
    Files.open(file);
    while( getline(Files, cline) ){
        std::istringstream parser(cline);
        int Position = 0;
        std::string name;
        int number;

        while( getline(parser, token, ',') ){
            if(Position == 0) {
                name = token;
                ++Position;
            }
            else {
                std::istringstream converter(token);    
                converter >> number;                
                Position = 0;

            }
        }
        push_back(list, Profession(name, number));
        std::cout << name << " " << number << "\n";
    }
    Files.close();
}

int main() {
    std::cout << std::endl;

    List list; 
    list.clear();

    std::cout << "PUSH\n";
    push_front(list, Profession("N/A", 400));
    push_front(list, Profession("N/A", 200));  
    push_front(list, Profession("N/A", 100));
    push_back(list, Profession("N/A", 600));  
    push_back(list, Profession("N/A", 800)); 
    push_back(list, Profession("N/A", 1000));
    push_back(list, Profession("N/A", 1200));                                                                                                                  
    print(list); 
    printRev(list);

    std::cout << "\nPOP\n";
    pop_front(list);
    pop_back(list);
    pop_back(list);
    print(list);
    printRev(list);    

    Iterator itr = list.begin();                              // point an iterator to the list

    std::cout << "\nFIND/INSERT\n";
    itr = find(list, Profession("N/A", 200));
    insert(list, itr, Profession("N/A", 100));                                   // insert 100 before 200 (edge case)
    itr = find(list, Profession("N/A", 400));
    insert(list, itr, Profession("N/A", 300));                                   // insert 300 before 400   
    itr = find(list, Profession("N/A", 800));
    insert(list, itr, Profession("N/A", 700));                                   // insert 700 before 800     
    print(list);
    printRev(list);    

    std::cout << "\nFIND/ERASE\n";    
    itr = find(list, Profession("N/A", 200));
    erase(list, itr);                                         // erase 100, the node before 200 (edge case)
    itr = find(list, Profession("N/A", 800));
    erase(list, itr);                                         // erase 700, the node before 800     
    print(list);
    printRev(list);  
          

    std::cout << "\nCOPY\n"; 
    List list_copy;
    duplicate(list, list_copy);                             // duplicate list without sharing memory
    print(list);
    print(list_copy);                               

    std::cout << "\nMEMORY INDEPENDENCE\n";  
    list.~List();                                           // erase list
    print(list_copy);                                       // print copy

    std::cout << "\nList Size\n";
    std::cout << list.getSize() <<std::endl;

    std::cout << "\nCsv\n";
    read("data.csv", list);
    std::cout << std::endl;
    print(list);
    
    std::cout << std::endl;
    return 0;
}
