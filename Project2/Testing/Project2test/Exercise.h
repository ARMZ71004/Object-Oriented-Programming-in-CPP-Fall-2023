#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <vector>

// Forward declaration of Athlete class
class Athlete;

class Exercise {
private:
    std::string name;
    int maxExercises;
    std::vector<Athlete*> athletes;

public:
    Exercise();
    Exercise(const std::string &name, int maxExercises);
    ~Exercise();

    std::string getName() const;
    int getMaxExercises() const;
    std::vector<Athlete*> getAthletes() const;

    void setName(const std::string &newName);
    void setMaxExercises(int newMaxExercises);
    void addAthlete(Athlete *athlete);
    void removeAthlete(Athlete *athlete);

    void displayAthletes() const;

    bool operator==(const Exercise &other) const;
    friend std::ostream& operator<<(std::ostream &out, const Exercise &exercise);
};

#endif
