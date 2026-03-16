#ifndef FILES_H
#define FILES_H

#include "Contestant.h"
#include "Race.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

void readContestant(std::vector<Contestant*>& contestants) {
    std::ifstream file("Contestant.csv");
    std::string line, name;
    int id, maxRaces;

    while (getline(file, line)) {
        std::istringstream cline(line);
        getline(cline, name, ',');
        cline >> id;
        contestants.push_back(new Contestant(name, id, maxRaces));
    }
};

void readRace(std::vector<Race*>& races) {
    std::ifstream file("Race.csv");
    std::string line, name;
    

    while (getline(file, line)) {
        std::istringstream cline(line);
        getline(cline, name, ',');
        races.push_back(new Race(name));
    }
}

template<typename T>
void print(const std::vector<T*>& container) {
    for (const auto& item : container) {
        std::cout << *item << std::endl;
    }
}

template<typename T>
void clear(std::vector<T*>& container) {
    for (auto& item : container) {
        delete item;
    }
    container.clear();
}

#endif
