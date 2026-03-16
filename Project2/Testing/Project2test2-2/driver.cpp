#include <iostream>
#include <fstream>
#include <sstream>
#include "Athlete.h"
#include "Exercise.h"
#include "Trainer.h"
#include "AthleteUI.h"
#include "TrainerUI.h"
#include "Files.h"

void readAthlete(std::vector<Athlete*>& athletes) {
    std::ifstream file("Athlete.csv");
    std::string line, name;
    int id;

    while (getline(file, line)) {
        std::istringstream ss(line);
        getline(ss, name, ',');
        ss >> id;
        athletes.push_back(new Athlete(name, id));
    }
}

void readExercise(std::vector<Exercise*>& exercises) {
    std::ifstream file("Exercise.csv");
    std::string line, exerciseName;
    int maxExercises;

    while (getline(file, line)) {
        std::istringstream ss(line);
        getline(ss, exerciseName, ',');
        ss >> maxExercises;
        exercises.push_back(new Exercise(exerciseName, maxExercises));
    }
}

void menu(std::vector<Athlete*>& athletes, std::vector<Exercise*>& exercises) {
    int option = 0;

    do {
        std::cout << "LOGIN AS Athlete OR Trainer\n\n";
        std::cout << "1) Athlete\n";
        std::cout << "2) Trainer\n";
        std::cout << "3) Exit program\n";
        std::cout << "\nSelect: ";
        std::cin >> option;
        std::cout << "\n";

        switch(option) {
            case 1: {
                AthleteUI athleteUI;
                athleteUI.menu(athletes, exercises);
                break;
            }
            case 2: {
                TrainerUI trainerUI;
                trainerUI.menu(athletes, exercises);
                break;
            }
            case 3:
                std::cout << "EXITING PROGRAM\n\n";
                break;
            default:
                std::cout << "INVALID OPTION" << "\n";
        }

    } while(option != 3);
}

int main() {   
    std::vector<Athlete*> athletes;
    std::vector<Exercise*> exercises;

    readAthlete(athletes);
    readExercise(exercises);

    menu(athletes, exercises);

    clear(athletes);
    clear(exercises);

    return 0;
}
