#ifndef TRAINERUI_H
#define TRAINERUI_H

#include "UserInterface.h"

class TrainerUI : public UserInterface {
public:
    void menu(std::vector<Athlete*>& athletes, std::vector<Exercise*>& exercises) override;
    void createExercise(std::vector<Exercise*>& exercises);
    void deleteExercise(std::vector<Exercise*>& exercises);
};

#endif
