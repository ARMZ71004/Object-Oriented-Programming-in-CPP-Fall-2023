#include "Athlete.h"
#include "Exercise.h"
#include <iostream>
#include <algorithm>

Athlete::Athlete() : name(""), id(0) {}

Athlete::Athlete(const std::string &name, int id) : name(name), id(id) {}

// Destructor
Athlete::~Athlete() {
}

std::string Athlete::getName() const {
    return name;
}

int Athlete::getId() const {
    return id;
}

std::vector<Exercise*> Athlete::getExercises() const {
    return exercises;
}

// Mutator functions
void Athlete::setName(const std::string &newName) {
    name = newName;
}

void Athlete::setId(int newId) {
    id = newId;
}

void Athlete::addExercise(Exercise *exercise) {
    if (std::find(exercises.begin(), exercises.end(), exercise) == exercises.end()) {
        exercises.push_back(exercise);
    }
}

void Athlete::removeExercise(Exercise *exercise) {
    auto it = std::find(exercises.begin(), exercises.end(), exercise);
    if (it != exercises.end()) {
        exercises.erase(it);
    }
}

// Display the exercises
void Athlete::displayExercises() const {
    for (const auto &exercise : exercises) {
        std::cout << *exercise << std::endl;
    }
}

// Overloaded Operators
bool Athlete::operator==(const Athlete &other) const {
    return id == other.id && name == other.name;
}

std::ostream& operator<<(std::ostream &out, const Athlete &athlete) {
    out << "Athlete Name: " << athlete.name << ", ID: " << athlete.id;
    return out;
}
