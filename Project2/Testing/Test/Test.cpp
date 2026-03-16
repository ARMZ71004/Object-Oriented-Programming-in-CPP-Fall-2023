#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Contestant.h"
#include "Race.h"

int main() {
    // Step 1: Instantiate a container of pointers to objects of type Contestants
    std::vector<Contestant*> contestants;

    // Step 2: Instantiate a container of pointers to objects of type Races
    std::vector<Race*> races;

    // Step 3: Instantiate iterators for both containers
    std::vector<Contestant*>::iterator contestantIter;
    std::vector<Race*>::iterator raceIter;

    // Step 4: Read data from Contestants.csv into the Contestants container
    std::ifstream contestantFile("Contestants.csv");
    if (contestantFile.is_open()) {
        std::string line;
        while (std::getline(contestantFile, line)) {
            std::istringstream iss(line);
            std::string name;
            int id, maxRaces;

            if (std::getline(iss, name, ',') &&
                (iss >> id) &&
                (iss.ignore(), iss >> maxRaces)) {
                Contestant* newContestant = new Contestant(name, id, maxRaces);
                contestants.push_back(newContestant);
            }
        }
        contestantFile.close();
    } else {
        std::cerr << "Unable to open Contestants.csv\n";
        return 1;
    }

    // Read data from Races.csv into the Races container
    std::ifstream raceFile("Races.csv");
    if (raceFile.is_open()) {
        std::string line;
        while (std::getline(raceFile, line)) {
            std::istringstream iss(line);
            // Assuming you have the necessary fields for the Race class
            // Adjust the code based on your actual Race class implementation
            // For example, you might need to read race details and create Race objects.
        }
        raceFile.close();
    } else {
        std::cerr << "Unable to open Races.csv\n";
        // Cleanup before returning
        for (contestantIter = contestants.begin(); contestantIter != contestants.end(); ++contestantIter) {
            delete *contestantIter;
        }
        return 1;
    }

    // Step 5: Test the read function and all class Contestants and Races functions core member functions
    // Add your testing code here

    // Step 6: Delete all dynamic memory created in the program
    for (contestantIter = contestants.begin(); contestantIter != contestants.end(); ++contestantIter) {
        delete *contestantIter;
    }
    contestants.clear();

    for (raceIter = races.begin(); raceIter != races.end(); ++raceIter) {
        delete *raceIter;
    }
    races.clear();

    return 0;
}
