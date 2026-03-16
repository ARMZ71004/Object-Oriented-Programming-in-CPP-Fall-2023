#include <iostream>
#include <sstream>
#include <fstream>

void read(){
    std::ifstream Files;
    std::string cline, token;
    Files.open("data.csv");
    while( getline(Files, cline) ){
        std::istringstream parser(cline);
        int Position = 0;
        std::string profession;
        int employees;

        while( getline(parser, token, ',') ){
            if(Position == 0) {
                profession = token;
                ++Position;
            }
            else {
                std::istringstream converter(token);    
                converter >> employees;                
                Position = 0;
            }
        }
        std::cout << profession << " " << employees << "\n";
    }
}
int main() {
    read();
    /*std::cout << std::endl;

    List list; 

    std::cout << "PUSH\n";
    push_front(list, 400);
    push_front(list, 200);  
    push_front(list, 100);
    push_back(list, 600);  
    push_back(list, 800); 
    push_back(list,1000);
    push_back(list,1200);                                                                                                                  
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
    itr = find(list, 200);
    insert(list, itr, 100);                                   // insert 100 before 200 (edge case)
    itr = find(list, 400);
    insert(list, itr, 300);                                   // insert 300 before 400   
    itr = find(list, 800);
    insert(list, itr, 700);                                   // insert 700 before 800     
    print(list);
    printRev(list);    

    std::cout << "\nFIND/ERASE\n";    
    itr = find(list, 200);
    erase(list, itr);                                         // erase 100, the node before 200 (edge case)
    itr = find(list, 800);
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

    std::cout << std::endl;*/
    return 0;
}
