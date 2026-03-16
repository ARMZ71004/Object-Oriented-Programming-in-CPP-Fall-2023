#include "TrainerUI.h"

void TrainerUI::menu(std::vector<Athlete*>& athletes, std::vector<Exercise*>& exercises) {
    int option = 0;

    do {
        std::cout << "\nTrainer Menu:\n";
        std::cout << "1. Display all exercises\n";
        std::cout << "2. Display all athletes\n";
        std::cout << "3. Add an exercise\n";
        std::cout << "4. Remove an exercise\n";
        std::cout << "5. Display athletes for an exercise\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch(option) {
            case 1:
                UserInterface::display(exercises);
                break;
            case 2:
                UserInterface::display(athletes);
                break;
            case 3:
                createExercise(exercises);
                break;
            case 4:
                deleteExercise(exercises);
                break;
            case 5:
                {
                    auto exerciseIt = UserInterface::selectExercise(exercises);
                    if(exerciseIt != exercises.end()) {
                        (*exerciseIt)->display();
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

void TrainerUI::createExercise(std::vector<Exercise*>& exercises) {
    std::string name;
    int maxExercises;
    std::cout << "Enter exercise name: ";
    std::cin >> name;
    std::cout << "Enter max number of exercises: ";
    std::cin >> maxExercises;

    exercises.push_back(new Exercise(name, maxExercises));
    std::cout << "Exercise created successfully.\n";
}

void TrainerUI::deleteExercise(std::vector<Exercise*>& exercises) {
    auto exerciseIt = UserInterface::selectExercise(exercises);
    if(exerciseIt != exercises.end()) {
        delete *exerciseIt;
        exercises.erase(exerciseIt);
        std::cout << "Exercise deleted successfully.\n";
    }
}




