#include <iostream>
#include "Athlete.h"
#include "Exercise.h"
#include "Files.h"

int main() {
    std::vector<Athlete*> athletes;
    std::vector<Exercise*> exercises;

    // Read data into containers
    readAthlete(athletes);
    readExercise(exercises);

    //Print athletes and exercises
    std::cout << "Athletes:\n";
    print(athletes);

    std::cout << "\nExercises:\n";
    print(exercises);

    //Linking athletes and exercises
    if (!athletes.empty() && !exercises.empty()) {
        athletes[0]->addExercise(exercises[0]); // Add first exercise to the first athlete
        exercises[0]->addAthlete(athletes[0]); // Add first athlete to the first exercise
    }

    // Display athletes and their exercises
    if (!athletes.empty()) {
        std::cout << "\nAthlete and their exercises:\n";
        std::cout << *athletes[0] << std::endl;
        athletes[0]->displayExercises();
    }

    // Display exercises and their athletes
    if (!exercises.empty()) {
        std::cout << "\nExercise and its athletes:\n";
        std::cout << *exercises[0] << std::endl;
        exercises[0]->displayAthletes();
    }

    //Delete all dynamically allocated objects
    clear(athletes);
    clear(exercises);

    return 0;
}
































/*#include <iostream>
#include "Athlete.h"
#include "Exercise.h"
// #include "Trainer.h"
// #include "AthleteUI.h"
// #include "TrainerUI.h"
#include "Files.h"


#include <iostream>
#include "Athlete.h"
#include "Exercise.h"

int main() {
    // Create a few exercises
    Exercise pushups("Pushups", 20);
    Exercise pullups("Pullups", 10);
    Exercise squats("Squats", 8);

    // Create a few athletes
    Athlete athlete1("John Doe", 1);
    Athlete athlete2("Jane Smith", 2);

    // Add exercises to athletes
    athlete1.addExercise(&pushups);
    athlete1.addExercise(&pullups);
    athlete2.addExercise(&squats);

    // Display athletes and their exercises
    std::cout << "Athlete 1: \n" << athlete1 << std::endl;
    athlete1.displayExercises();

    std::cout << "\nAthlete 2: \n" << athlete2 << std::endl;
    athlete2.displayExercises();

    // Testing removal of an exercise
    std::cout << "\nRemoving 'Pullups' from Athlete 1's exercises.\n";
    athlete1.removeExercise(&pullups);

    std::cout << "Athlete 1 after removal: \n" << athlete1 << std::endl;
    athlete1.displayExercises();

    // Test overloaded equality operator
    if (athlete1 == athlete2) {
        std::cout << "\nAthlete 1 and Athlete 2 are the same.\n";
    } else {
        std::cout << "\nAthlete 1 and Athlete 2 are different.\n";
    }

    return 0;
}*/




/*int main() {
    
    // std::vector<Athlete*> athletes;
    // std::vector<Exercise*> exercises;
    // std::vector<Trainer*> trainers;

    // // Assuming you have functions in Files.h to read data into these containers
    // readAthletes(athletes, "athletes.csv");
    // readExercises(exercises, "exercises.csv");
    // readTrainers(trainers, "trainers.csv");

    // // Create instances of the UI classes
    // AthleteUI athleteUI;
    // TrainerUI trainerUI;

    // // Main application loop
    // bool running = true;
    // while (running) {
    //     // Example of menu options
    //     std::cout << "1. Athlete Menu\n";
    //     std::cout << "2. Trainer Menu\n";
    //     std::cout << "3. Exit\n";
    //     std::cout << "Enter your choice: ";

    //     int choice;
    //     std::cin >> choice;

    //     switch (choice) {
    //         case 1:
    //             athleteUI.menu(athletes, exercises);
    //             break;
    //         case 2:
    //             trainerUI.menu(exercises, trainers);
    //             break;
    //         case 3:
    //             running = false;
    //             break;
    //         default:
    //             std::cout << "Invalid option. Please try again.\n";
    //     }
    // }

    // // Clean up dynamically allocated memory
    // for (auto athlete : athletes) {
    //     delete athlete;
    // }
    // for (auto exercise : exercises) {
    //     delete exercise;
    // }
    // for (auto trainer : trainers) {
    //     delete trainer;
    // }

    return 0;
}
*/