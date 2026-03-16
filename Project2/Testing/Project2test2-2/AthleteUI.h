#ifndef ATHLETEUI_H
#define ATHLETEUI_H

#include "UserInterface.h"

class AthleteUI : public UserInterface {
public:
    void menu(std::vector<Athlete*>& athletes, std::vector<Exercise*>& exercises) override;
    void addExercise(std::vector<Athlete*>::iterator athleteIt, std::vector<Exercise*>& exercises);
    void removeExercise(std::vector<Athlete*>::iterator athleteIt, std::vector<Exercise*>::iterator exerciseIt);
};

#endif
