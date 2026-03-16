// S. Trowbridge 2023
#include <iostream>
#include <sstream>    // required for stringstream
#include <fstream>    // required for file input

int main() {
    std::cout << std::endl;

    std::ifstream myFile("data.csv");               // create object and open file
    std::string line, token;                        // variables to store file information

    while( getline(myFile, line) ) {                // read a line from the file
        std::istringstream parser(line);            // connect a stringstream object to the line

        while( getline(parser, token, ',') ) {      // separate the line into tokens (using the , delimiter)
            std::cout << token << "\n";             // output each individual token
        }
        std::cout << "\n";
        
    }

    myFile.close();                                 // close file object

    std::cout << std::endl;
    return 0;
}
