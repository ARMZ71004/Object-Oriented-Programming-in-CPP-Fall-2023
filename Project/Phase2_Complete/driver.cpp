#include <iostream>
#include <sstream>
#include <fstream>
#include "Node.h"
#include "List.h"
#include "Iterator.h"
#include "Profession.h"

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
    Profession a = Profession("1",400);
    Profession b = Profession("2",300);
    std::cout << compare(a, b, true);
    return 0;
}
