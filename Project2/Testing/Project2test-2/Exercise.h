#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <vector>

class Athlete;  // Forward declaration

class Exercise {
private:
    std::string name;                  // Name of the exercise
    int maxExercises;                  // Maximum number of exercises in a workout
    std::vector<Athlete*> athletes;    // Container of pointers to Athlete objects

public:
    Exercise();
    Exercise(const std::string &name, int maxExercises);
    ~Exercise();

    std::string getName() const;
    void setName(const std::string &newName);

    int getMaxExercises() const;
    void setMaxExercises(int newMaxExercises);

    void addAthlete(Athlete* athlete);
    void removeAthlete(Athlete* athlete);
    void clearAthletes();

    std::vector<Athlete*> getAthletes() const;

    void display() const;

    bool operator==(const Exercise &other) const;
    friend std::ostream& operator<<(std::ostream &out, const Exercise &exercise);
};

#endif // EXERCISE_H
