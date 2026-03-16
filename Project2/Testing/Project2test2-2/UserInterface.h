#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Athlete.h"
#include "Exercise.h"
#include <vector>
#include <iostream>

class UserInterface {
public:
    virtual void menu(std::vector<Athlete*>& athletes, std::vector<Exercise*>& exercises) = 0;

    template<typename T>
    static void display(const std::vector<T*>& container) {
        for (const auto& item : container) {
            std::cout << *item << std::endl;
        }
    }

    static std::vector<Athlete*>::iterator selectAthlete(std::vector<Athlete*>& athletes) {
        size_t choice;
        display(athletes);

        std::cout << "Select an athlete by number: ";
        std::cin >> choice;

        if (choice > 0 && choice <= athletes.size()) {
            return athletes.begin() + (choice - 1);
        } else {
            return athletes.end();
        }
    }

    static std::vector<Exercise*>::iterator selectExercise(std::vector<Exercise*>& exercises) {
        size_t choice;
        display(exercises);

        std::cout << "Select an exercise by number: ";
        std::cin >> choice;

        if (choice > 0 && choice <= exercises.size()) {
            return exercises.begin() + (choice - 1);
        } else {
            return exercises.end();
        }
    }
};

#endif
