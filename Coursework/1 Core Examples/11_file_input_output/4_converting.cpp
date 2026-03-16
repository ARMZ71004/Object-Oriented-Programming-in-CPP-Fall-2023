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
        std::string country;                            // store string data
        std::string state;                              // store string data
        int population;                                 // store numerical data
 
        while( getline(parser, token, ',') ) {          // separate the line into tokens (using the , delimiter)

            if(tokenPosition == 0) {                    
                country = token;                        // store first string token into country
                ++tokenPosition;
            } else if (tokenPosition == 1) {
                state = token;                          // store first string token into country
                ++tokenPosition;            
            } else {
                std::istringstream converter(token);    // store third string token into a new istringstream object
                converter >> population;                // convert the string into an integer and store in population
                total += population;                    // add population to the total (this works because population is an integer, not a string)
                tokenPosition = 0;     
            }
        }

        std::cout << country << " " << state << " " << population << "\n";  
    }
    std::cout << "\nTotal population is: " << total << std::endl;

    myFile.close();                                     // close file object

    std::cout << std::endl;
    return 0;
}
