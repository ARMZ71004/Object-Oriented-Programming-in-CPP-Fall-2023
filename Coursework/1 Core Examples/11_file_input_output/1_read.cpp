// S. Trowbridge 2023
#include <iostream>
#include <fstream>    // required for ifstream/ofstream objects

int main( ) {
    std::cout << std::endl;

    // read data
    std::ifstream myFile;                   // create a file input object
    myFile.open("data.csv");                // open the input file

    std::string line;                       // variable to store each line from the file, one at a time
    while( getline(myFile, line) ) {        // while the file contains more text, store the current line of text into line
        std::cout << line << std::endl;     //      print line
    }

    myFile.close();                         // close the input file 

    std::cout << std::endl;
    return 0;
}
