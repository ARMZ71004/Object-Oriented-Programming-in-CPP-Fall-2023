#include <iostream>
#include <fstream>
#include <sstream>
#include "Contestant.h"
#include "Coordinator.h"
#include "Race.h"
#include "Files.h"
#include "CoordinatorUI.h"
#include "ContestantUI.h"
#include "UserInterface.h"

void menu(std::vector<Contestant*>& contestants, std::vector<Race*>& races) {
    int option = 0;

    do {
        std::cout << "\n\nEnter Number Correlated to Option\n\n";
        std::cout << "1) Contestant\n";
        std::cout << "2) Trainer\n";
        std::cout << "3) Exit program\n";
        std::cout << "\nSelect: ";
        std::cin >> option;
        std::cout << "\n";

        switch(option) {
            case 1: {
                ContestantUI ContestantUI;
                ContestantUI.menu(contestants, races);
                break;
            }
            case 2: {
                CoordinatorUI Cui;
                Cui.menu(contestants, races);
                break;
            }
            case 3:
                std::cout << "Program Ending\n\n";
                break;
            default:
                std::cout << "INVALID" << "\n";
        }

    } while(option != 3);
}

int main() {
    std::vector<Contestant*> contestants;
    std::vector<Race*> races;

    std::vector<Contestant*>::iterator contestantIterator;
    std::vector<Race*>::iterator raceIterator;

    //files.h
    readContestant(contestants);
    readRace(races);
    /*
    for (std::vector<Contestant*>::size_type i = 0; i < contestants.size(); ++i) {
        std::vector<Race*>::size_type racesAssigned = 0; 
        for (std::vector<Race*>::size_type j = 0; j < races.size() && racesAssigned < contestants[i]->getMaxRaces(); ++j) {
            contestants[i]->addRace(races[j]);
            races[j]->addContestant(contestants[i]);
            ++racesAssigned;
        }
    }*/
    menu(contestants, races);

    print(races);

    clear(contestants);
    clear(races);

    return 0;
}
