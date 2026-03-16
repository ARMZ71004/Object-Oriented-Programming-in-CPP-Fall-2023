#include <iostream>
#include <fstream>
#include <sstream>
#include "Athlete.h"
#include "Exercise.h"
#include "Trainer.h"
#include "Files.h"

// Function to read Athlete objects from Athlete.csv
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

// Function to read Exercise objects from Exercise.csv
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

int main() {
    std::vector<Athlete*> athletes;
    std::vector<Exercise*> exercises;

    // Read data into containers
    readAthlete(athletes);
    readExercise(exercises);

    // Print athletes and exercises
    std::cout << "Athletes:\n";
    print(athletes);

    std::cout << "\nExercises:\n";
    print(exercises);

    // Linking each athlete to each exercise
    for (size_t i = 0; i < athletes.size(); ++i) {
        for (size_t j = 0; j < exercises.size(); ++j) {
            if (j % athletes.size() == i) {
                athletes[i]->addExercise(exercises[j]);
                exercises[j]->addAthlete(athletes[i]);
            }
        }
    }
    // Display athletes and their exercises
    std::cout << "\nAthlete and their exercises:\n";
    for (auto& athlete : athletes) {
        athlete->display();  // Assuming Athlete class has a display method
    }

    // Display exercises and their athletes
    std::cout << "\nExercise and its athletes:\n";
    for (auto& exercise : exercises) {
        exercise->display();  // Assuming Exercise class has a display method
    }

    // Integrate Trainer functionality
    Trainer trainer;

    // Example: Creating a new exercise via Trainer
    trainer.createExercise(exercises, "Lunges", 15);

    // Example: Finding and removing an exercise via Trainer
    auto exerciseIt = trainer.findExercise(exercises, "Pullups");
    if (exerciseIt != exercises.end()) {
        trainer.removeExercise(exercises, *exerciseIt);
    }

    // Print updated exercises list
    std::cout << "\nUpdated Exercises:\n";
    print(exercises);

    // Delete all dynamically allocated objects
    clear(athletes);
    clear(exercises);

    return 0;
}
