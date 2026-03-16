#ifndef FILES_H
#define FILES_H

#include "Athlete.h"
#include "Exercise.h"
#include <vector>
#include <iostream>

// Declaration of read functions; Definitions will be in driver.cpp
void readAthlete(std::vector<Athlete*>& athletes);
void readExercise(std::vector<Exercise*>& exercises);

template<typename T>
void print(const std::vector<T*>& container) {
    for (const auto& item : container) {
        std::cout << *item << std::endl;
    }
}

template<typename T>
void clear(std::vector<T*>& container) {
    for (auto& item : container) {
        delete item;
    }
    container.clear();
}

#endif // FILES_H
