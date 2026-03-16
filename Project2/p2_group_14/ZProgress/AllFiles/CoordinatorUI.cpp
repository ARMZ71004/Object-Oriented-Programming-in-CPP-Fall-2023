#include "CoordinatorUI.h"

void CoordinatorUI::menu(std::vector<Contestant*>& contestants, std::vector<Race*>& races) {
    char pl;
    do{
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "Coordinator Menu:" << std::endl;
        std::cout << "A - Display all Races" << std::endl;
        std::cout << "B - Display all Contestants." << std::endl;
        std::cout << "C - Add Race." << std::endl;
        std::cout << "D - Remove Race." << std::endl;
        std::cout << "E - Race and its Contestants." << std::endl;
        std::cout << "F - Exit" << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    
        std::cout << "Enter Cooresponding Letter: ";
        std::cin >> pl;

        switch (pl) {
            case 'A':
                UserInterface::display(races);
                break;
            case 'B':
                UserInterface::display(contestants);
                break;
            case 'C':
                createRace(races.begin(), races);
                break;
            case 'D':
                deleteRace(races);
                break;
            case 'E':
                {
                    auto racesIt = UserInterface::selectRace(races);
                    if(racesIt != races.end()) {
                        (*racesIt)->displayC();
                    }
                }
                break;
            case 'F':
                break; 
            default:
                std::cout << "Invalid Option. Try again" << std::endl;
        }
    }while(pl != 'F');
}
///*
void CoordinatorUI::createRace(std::vector<Race*>::iterator raceIt, std::vector<Race*>& races) {
    std::cout << "Select a Race to add the contestant:\n";
    auto selectedRace = UserInterface::selectRace(races);
    if (selectedRace != races.end()) {
        std::cout << "Select a Contestant for the race:\n";
        auto selectedContestant = UserInterface::selectContestant((*selectedRace)->getContestants());

        if (selectedContestant != (*selectedRace)->getContestants().end()) {
            (*selectedRace)->addContestant(*selectedContestant);
            std::cout << "Contestant added to the race\n";
        } else {
            std::cout << "Invalid contestant selection\n";
        }
    } else {
        std::cout << "Invalid race selection\n";
    }
}
void CoordinatorUI::createRace(std::vector<Race*>::iterator raceIt, std::vector<Race*>& races) {
    std::cout << "Select a Race to add the contestant:\n";
    auto selectedRace = UserInterface::selectRace(races);
    if (selectedRace != races.end()) {
        std::cout << "Select a Contestant for the race:\n";
        auto selectedContestant = UserInterface::selectContestant((*selectedRace)->getContestants());

        if (selectedContestant != (*selectedRace)->getContestants().end()) {
            (*selectedRace)->addContestant(*selectedContestant);
            std::cout << "Contestant added to the race\n";
        } else {
            std::cout << "Invalid contestant selection\n";
        }
    } else {
        std::cout << "Invalid race selection\n";
    }
}



void CoordinatorUI::deleteRace(std::vector<Race*>& races) {
    std::cout << "Select a Race to delete:\n";
    auto selectedRace = UserInterface::selectRace(races);

    if (selectedRace != races.end()) {
        std::cout << "Select a Contestant to remove from the race:\n";
        auto selectedContestant = UserInterface::selectContestant((*selectedRace)->getContestants());

        if (selectedContestant != (*selectedRace)->getContestants().end()) {
            (*selectedRace)->removeContestant(*selectedContestant);
            std::cout << "Contestant removed from the race.\n";
        } else {
            std::cout << "Invalid contestant selection.\n";
        }
    } else {
        std::cout << "Invalid race selection.\n";
    }
}//*/



