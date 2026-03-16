# Executable file to create and its dependencies
prog: Athlete.o Exercise.o Files.o driver.o
	g++ -std=c++11 -o prog Athlete.o Exercise.o Files.o driver.o

# File dependencies
Athlete.o: Athlete.cpp Athlete.h
	g++ -std=c++11 -c Athlete.cpp

Exercise.o: Exercise.cpp Exercise.h
	g++ -std=c++11 -c Exercise.cpp

Files.o: Files.cpp Files.h Athlete.h Exercise.h
	g++ -std=c++11 -c Files.cpp

driver.o: driver.cpp Athlete.h Exercise.h Files.h
	g++ -std=c++11 -c driver.cpp

# Files to remove
clean:
	del -f Athlete.o Exercise.o Files.o driver.o prog
