#include "Files.h"
#include <fstream>
#include <sstream>
#include <iostream>

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

