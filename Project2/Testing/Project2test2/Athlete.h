#ifndef ATHLETE_H
#define ATHLETE_H

#include <string>
#include <vector>
#include "Exercise.h"  // Include Exercise class

class Athlete {
private:
    std::string name;                  // Full name of the athlete
    int id;                            // Athlete ID number
    std::vector<Exercise*> exercises;  // Container of pointers to Exercise objects

public:
    Athlete();
    Athlete(const std::string &name, int id);
    ~Athlete();

    std::string getName() const;
    void setName(const std::string &newName);

    int getId() const;
    void setId(int newId);

    void addExercise(Exercise* exercise);
    void removeExercise(Exercise* exercise);
    void clearExercises();

    std::vector<Exercise*> getExercises() const;
    size_t getNumExercises() const;

    void display() const;

    bool operator==(const Athlete &other) const;
    friend std::ostream& operator<<(std::ostream &out, const Athlete &athlete);
};

#endif // ATHLETE_H
