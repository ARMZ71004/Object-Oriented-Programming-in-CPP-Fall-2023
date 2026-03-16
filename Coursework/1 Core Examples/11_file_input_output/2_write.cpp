// S. Trowbridge 2023
#include <iostream>
#include <fstream>    // required for ifstream/ofstream objects

int main( ) {
    std::cout << std::endl;

    // write data
    std::ofstream myFile;                                 // create file output object
    
    myFile.open("blank.csv");                              // open a file to write to

    for(int i=1; i<=3; i++) {
        myFile << "Line " << i << " some text.\n";        // write line to file
    }

    myFile.close();                                       // close output file

    std::cout << std::endl;
    return 0;
}
