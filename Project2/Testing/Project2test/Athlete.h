#ifndef ATHLETE_H
#define ATHLETE_H

#include <string>
#include <vector>

// Forward declaration of Exercise class
class Exercise;

class Athlete {
private:
    std::string name;
    int id;
    std::vector<Exercise*> exercises;

public:
    Athlete();
    Athlete(const std::string &name, int id);
    ~Athlete();

    std::string getName() const;
    int getId() const;
    std::vector<Exercise*> getExercises() const;

    void setName(const std::string &name);
    void setId(int id);
    void addExercise(Exercise *exercise);
    void removeExercise(Exercise *exercise);

    void displayExercises() const;

    bool operator==(const Athlete &other) const;
    friend std::ostream& operator<<(std::ostream &out, const Athlete &athlete);
};

#endif
