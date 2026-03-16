#include "Exercise.h"
#include "Athlete.h"
#include <iostream>
#include <algorithm>

// Default Constructor
Exercise::Exercise() : name(""), maxExercises(0) {}

// Parameterized Constructor
Exercise::Exercise(const std::string &name, int maxExercises) : name(name), maxExercises(maxExercises) {}

// Destructor
Exercise::~Exercise() {
}

// Accessor functions
std::string Exercise::getName() const {
    return name;
}

int Exercise::getMaxExercises() const {
    return maxExercises;
}

std::vector<Athlete*> Exercise::getAthletes() const {
    return athletes;
}

// Mutator functions
void Exercise::setName(const std::string &newName) {
    name = newName;
}

void Exercise::setMaxExercises(int newMaxExercises) {
    maxExercises = newMaxExercises;
}

void Exercise::addAthlete(Athlete *athlete) {
    if (static_cast<int>(athletes.size()) < maxExercises && std::find(athletes.begin(), athletes.end(), athlete) == athletes.end()) {
        athletes.push_back(athlete);
    }
}

void Exercise::removeAthlete(Athlete *athlete) {
    auto it = std::find(athletes.begin(), athletes.end(), athlete);
    if (it != athletes.end()) {
        athletes.erase(it);
    }
}

// Display the athletes
void Exercise::displayAthletes() const {
    for (const auto &athlete : athletes) {
        std::cout << *athlete << std::endl;
    }
}

// Overloaded Operators
bool Exercise::operator==(const Exercise &other) const {
    return name == other.name && maxExercises == other.maxExercises;
}

std::ostream& operator<<(std::ostream &out, const Exercise &exercise) {
    out << "Exercise Name: " << exercise.name << ", Max Exercises: " << exercise.maxExercises;
    return out;
}
