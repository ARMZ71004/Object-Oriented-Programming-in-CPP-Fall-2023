#ifndef TRAINER_H
#define TRAINER_H

#include "Exercise.h"
#include <vector>
#include <string>

class Trainer {
public:
    // Member Functions
    std::vector<Exercise*>::iterator findExercise(std::vector<Exercise*>& exercises, const std::string& exerciseName);
    void createExercise(std::vector<Exercise*>& exercises, const std::string &name, int maxExercises);
    void removeExercise(std::vector<Exercise*>& exercises, Exercise* exercise);
};

#endif // TRAINER_H
