#include "Athlete.h"
#include <iostream>
#include <algorithm>

Athlete::Athlete() : name(""), id(0) {}

Athlete::Athlete(const std::string &name, int id) : name(name), id(id) {}

Athlete::~Athlete() {
    clearExercises();
}

std::string Athlete::getName() const {
    return name;
}

void Athlete::setName(const std::string &newName) {
    name = newName;
}

int Athlete::getId() const {
    return id;
}

void Athlete::setId(int newId) {
    id = newId;
}

void Athlete::addExercise(Exercise* exercise) {
    if (std::find(exercises.begin(), exercises.end(), exercise) == exercises.end()) {
        exercises.push_back(exercise);
        exercise->addAthlete(this);  // Also add this athlete to the exercise
    }
}

void Athlete::removeExercise(Exercise* exercise) {
    auto it = std::find(exercises.begin(), exercises.end(), exercise);
    if (it != exercises.end()) {
        exercises.erase(it);
        exercise->removeAthlete(this);  // Also remove this athlete from the exercise
    }
}

void Athlete::clearExercises() {
    for (auto& exercise : exercises) {
        exercise->removeAthlete(this);
    }
    exercises.clear();
}

std::vector<Exercise*> Athlete::getExercises() const {
    return exercises;
}

size_t Athlete::getNumExercises() const {
    return exercises.size();
}

void Athlete::display() const {
    std::cout << "Athlete Name: " << name << ", ID: " << id << std::endl;
    std::cout << "Exercises:" << std::endl;
    for (const auto& exercise : exercises) {
        std::cout << exercise->getName() << std::endl;
    }
}

bool Athlete::operator==(const Athlete &other) const {
    return id == other.id && name == other.name;
}

std::ostream& operator<<(std::ostream &out, const Athlete &athlete) {
    out << "Athlete Name: " << athlete.name << ", ID: " << athlete.id;
    return out;
}
