# Executable file to create and its dependencies
prog: Athlete.o Exercise.o Trainer.o driver.o
	g++ -std=c++11 -o prog Athlete.o Exercise.o Trainer.o driver.o

# File dependencies
Athlete.o: Athlete.cpp Athlete.h
	g++ -std=c++11 -c Athlete.cpp

Exercise.o: Exercise.cpp Exercise.h
	g++ -std=c++11 -c Exercise.cpp

Trainer.o: Trainer.cpp Trainer.h
	g++ -std=c++11 -c Trainer.cpp

driver.o: driver.cpp Athlete.h Exercise.h Trainer.h Files.h
	g++ -std=c++11 -c driver.cpp

# Files to remove
clean:
	del -f Athlete.o Exercise.o Trainer.o driver.o prog
