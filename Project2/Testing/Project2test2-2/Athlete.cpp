#include "Athlete.h"
#include <iostream>
#include <iomanip>
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
        exercise->addAthlete(this); 
    }
}

void Athlete::removeExercise(Exercise* exercise) {
    auto it = std::find(exercises.begin(), exercises.end(), exercise);
    if (it != exercises.end()) {
        exercises.erase(it);
        exercise->removeAthlete(this);
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
    const int idWidth = 10;
    const int nameWidth = 20;
    const int exerciseWidth = 30;

    std::cout << std::left << std::setw(idWidth) << "ID" 
              << std::setw(nameWidth) << "Name" 
              << "Exercises" << std::endl;

    std::cout << std::left << std::setw(idWidth) << id 
              << std::setw(nameWidth) << name;

    if (exercises.empty()) {
        std::cout << "No exercises assigned." << std::endl;
    } else {
        for (const auto& exercise : exercises) {
            std::cout << exercise->getName() << ", ";
        }
        std::cout << std::endl;
    }
}

bool Athlete::operator==(const Athlete &other) const {
    return id == other.id && name == other.name;
}

std::ostream& operator<<(std::ostream &out, const Athlete &athlete) {
    out << std::left << std::setw(10) << athlete.id 
        << std::setw(20) << athlete.name;
    return out;
}
