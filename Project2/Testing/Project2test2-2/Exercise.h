#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <vector>

class Athlete;  // Forward declaration

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
    void setName(const std::string &newName);

    int getMaxExercises() const;
    void setMaxExercises(int newMaxExercises);

    void addAthlete(Athlete* athlete);
    void removeAthlete(Athlete* athlete);
    
    bool isMaxed() const;              
    void increaseMax();               

    void clearAthletes();

    std::vector<Athlete*> getAthletes() const;

    void display() const;

    bool operator==(const Exercise &other) const;
    friend std::ostream& operator<<(std::ostream &out, const Exercise &exercise);
};

#endif 
