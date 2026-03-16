#include "AthleteUI.h"

void AthleteUI::menu(std::vector<Athlete*>& athletes, std::vector<Exercise*>& exercises) {
    int option = 0;
    std::vector<Athlete*>::iterator selectedAthleteIt = athletes.end();

    do {
        std::cout << "\nAthlete Menu:\n";
        std::cout << "1. Display all athletes\n";
        std::cout << "2. Select an athlete\n";
        std::cout << "3. Display athlete's exercises\n";
        std::cout << "4. Add an exercise for the athlete\n";
        std::cout << "5. Remove an exercise from the athlete\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        if ((option == 3 || option == 4 || option == 5) && selectedAthleteIt == athletes.end()) {
            std::cout << "Please select an athlete first.\n";
            continue;
        }

        switch(option) {
            case 1:
                UserInterface::display(athletes);
                break;
            case 2:
                selectedAthleteIt = UserInterface::selectAthlete(athletes);
                break;
            case 3:
                if(selectedAthleteIt != athletes.end()) {
                    (*selectedAthleteIt)->display();
                }
                break;
            case 4:
                if(selectedAthleteIt != athletes.end()) {
                    addExercise(selectedAthleteIt, exercises);
                }
                break;
            case 5:
                if(selectedAthleteIt != athletes.end()) {
                    auto exerciseIt = UserInterface::selectExercise(exercises);
                    if(exerciseIt != exercises.end()) {
                        removeExercise(selectedAthleteIt, exerciseIt);
                    }
                }
                break;
            case 6:
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (option != 6);
}

void AthleteUI::addExercise(std::vector<Athlete*>::iterator athleteIt, std::vector<Exercise*>& exercises) {
    auto exerciseIt = UserInterface::selectExercise(exercises);
    if(exerciseIt != exercises.end()) {
        (*athleteIt)->addExercise(*exerciseIt);
        std::cout << "Exercise added successfully.\n";
    }
}

void AthleteUI::removeExercise(std::vector<Athlete*>::iterator athleteIt, std::vector<Exercise*>::iterator exerciseIt) {
    (*athleteIt)->removeExercise(*exerciseIt);
    std::cout << "Exercise removed successfully.\n";
}
