#include "Trainer.h"
#include "Athlete.h"
#include <algorithm>


std::vector<Exercise*>::iterator Trainer::findExercise(std::vector<Exercise*>& exercises, const std::string& exerciseName) {
    return std::find_if(exercises.begin(), exercises.end(), [&exerciseName](const Exercise* exercise) {
        return exercise->getName() == exerciseName;
    });
}

void Trainer::createExercise(std::vector<Exercise*>& exercises, const std::string &name, int maxExercises) {
    exercises.push_back(new Exercise(name, maxExercises));
}

void Trainer::removeExercise(std::vector<Exercise*>& exercises, Exercise* exercise) {
    if (exercise != nullptr) {
        for (auto& athlete : exercise->getAthletes()) {
            athlete->removeExercise(exercise);
        }
        exercises.erase(std::remove(exercises.begin(), exercises.end(), exercise), exercises.end());
        delete exercise;
    }
}
