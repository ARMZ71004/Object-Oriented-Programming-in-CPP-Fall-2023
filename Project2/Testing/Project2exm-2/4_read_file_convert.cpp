// S. Trowbridge 2023
#include <iostream>
#include <sstream>    // required for stringstream
#include <fstream>    // required for file input

int main() {
    std::cout << std::endl;

    std::ifstream myFile("data.csv");                   // create object and open file
    std::string line, token;                            // variables to store file information

    long long total = 0;
    while( getline(myFile, line) ) {                    // read a line from the file
        std::istringstream parser(line);                // connect a stringstream object to the line

        int tokenPosition = 0;                          // keep track of which value we are reading
        std::string country, state;                     // store string data
        int population;                                 // store numerical data
 
        while( getline(parser, token, ',') ) {          // separate the line into tokens (using the , delimiter)

            if(tokenPosition == 0) {                    // token position keeps track of which block we are reading (separate by the , in the file)
                country = token;                        // store first token into the string country
                ++tokenPosition;                        // increment token to tell program we read the first block of text
            } else if (tokenPosition == 1) {
                state = token;                          // store second token into string state
                ++tokenPosition;                        // increment token to tell program we read the second block of text  
            } else {
                std::istringstream converter(token);    // associate a istringstream object with the token
                converter >> population;                // use the istringstream object to convert token into the integer population
                total += population;                    // add population to the total (this works because population is an integer, not a string)
                tokenPosition = 0;                      // reset position to read the next row of text     
            }
        }
        std::cout << country << " " << state << " " << population << "\n";  
    }
    std::cout << total << std::endl;                    // print the sum of populations of each row

    myFile.close();                                     // close file object

    std::cout << std::endl;
    return 0;
}
