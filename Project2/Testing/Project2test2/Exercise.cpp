#include "Exercise.h"
#include "Athlete.h"
#include <iostream>
#include <algorithm>

Exercise::Exercise() : name(""), maxExercises(0) {}

Exercise::Exercise(const std::string &name, int maxExercises) : name(name), maxExercises(maxExercises) {}

Exercise::~Exercise() {
    clearAthletes();
}

std::string Exercise::getName() const {
    return name;
}

void Exercise::setName(const std::string &newName) {
    name = newName;
}

int Exercise::getMaxExercises() const {
    return maxExercises;
}

void Exercise::setMaxExercises(int newMaxExercises) {
    maxExercises = newMaxExercises;
}

void Exercise::addAthlete(Athlete* athlete) {
    if (std::find(athletes.begin(), athletes.end(), athlete) == athletes.end()) {
        athletes.push_back(athlete);
    }
}

void Exercise::removeAthlete(Athlete* athlete) {
    auto it = std::find(athletes.begin(), athletes.end(), athlete);
    if (it != athletes.end()) {
        athletes.erase(it);
    }
}

void Exercise::clearAthletes() {
    athletes.clear();
}

std::vector<Athlete*> Exercise::getAthletes() const {
    return athletes;
}

void Exercise::display() const {
    for (const auto& athlete : athletes) {
        std::cout << *athlete << std::endl;
    }
}

bool Exercise::operator==(const Exercise &other) const {
    return name == other.name && maxExercises == other.maxExercises;
}

std::ostream& operator<<(std::ostream &out, const Exercise &exercise) {
    out << "Exercise Name: " << exercise.name << ", Max Exercises: " << exercise.maxExercises;
    return out;
}
