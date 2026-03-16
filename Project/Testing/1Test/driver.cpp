#include <iostream>
#include <sstream>
#include <fstream>
#include "Node.h"
#include "List.h"
#include "Iterator.h"
// add the list code to list files bring back drive code in main and test .get profession.h and cpp . update node to include profession. 
//update list to include profession. update read function to add push back function to store profession object in the data structure
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
        std::cout << name << " " << number << "\n";
    }
}

int main() {
    std::cout << std::endl;

    List list; 
    read("data.csv", list);
    std::cout << "\nPUSH\n";
    list.push_front(list, 400);
    list.push_front(list, 200);  
    list.push_front(list, 100);
    list.push_back(list, 600);  
    list.push_back(list, 800); 
    list.push_back(list,1000);
    list.push_back(list,1200);                                                                                                                  
    list.print(list); 
    list.printRev(list);

    std::cout << "\nPOP\n";
    list.pop_front(list);
    list.pop_back(list);
    list.pop_back(list);
    list.print(list);
    list.printRev(list);    

    Iterator itr = list.begin();                              // point an iterator to the list

    std::cout << "\nFIND/INSERT\n";
    itr = list.find(list, 200);
    list.insert(list, itr, 100);                                   // insert 100 before 200 (edge case)
    itr = list.find(list, 400);
    list.insert(list, itr, 300);                                   // insert 300 before 400   
    itr = list.find(list, 800);
    list.insert(list, itr, 700);                                   // insert 700 before 800     
    list.print(list);
    list.printRev(list);    

    std::cout << "\nFIND/ERASE\n";    
    itr = list.find(list, 200);
    list.erase(list, itr);                                         // erase 100, the node before 200 (edge case)
    itr = list.find(list, 800);
    list.erase(list, itr);                                         // erase 700, the node before 800     
    list.print(list);
    list.printRev(list);  
          

    std::cout << "\nCOPY\n"; 
    List list_copy;
    list.duplicate(list, list_copy);                             // duplicate list without sharing memory
    list.print(list);
    list.print(list_copy);                               

    std::cout << "\nMEMORY INDEPENDENCE\n";  
    list.~List();                                           // erase list
    list.print(list_copy);                                       // print copy

    std::cout << std::endl;
    return 0;
}
