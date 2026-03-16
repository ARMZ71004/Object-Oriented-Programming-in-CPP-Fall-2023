#include "Trainer.h"
#include "Athlete.h"
#include <algorithm>

// Find an exercise by name
std::vector<Exercise*>::iterator Trainer::findExercise(std::vector<Exercise*>& exercises, const std::string& exerciseName) {
    return std::find_if(exercises.begin(), exercises.end(), [&exerciseName](const Exercise* exercise) {
        return exercise->getName() == exerciseName;
    });
}

// Create a new exercise and add it to the exercises container
void Trainer::createExercise(std::vector<Exercise*>& exercises, const std::string &name, int maxExercises) {
    exercises.push_back(new Exercise(name, maxExercises));
}

// Remove an exercise from the exercises container and from all athletes
void Trainer::removeExercise(std::vector<Exercise*>& exercises, Exercise* exercise) {
    if (exercise != nullptr) {
        // Remove this exercise from every athlete's list
        for (auto& athlete : exercise->getAthletes()) {
            athlete->removeExercise(exercise);
        }
        // Remove the exercise from the exercises vector
        exercises.erase(std::remove(exercises.begin(), exercises.end(), exercise), exercises.end());
        delete exercise; // Assuming dynamic allocation
    }
}
