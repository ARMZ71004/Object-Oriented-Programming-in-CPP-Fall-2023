# Executable file to create and its dependencies
prog: Contestant.o Coordinator.o Race.o driver.o
	g++ -std=c++11 -o prog Contestant.o Coordinator.o Race.o driver.o

# File dependencies
Contestant.o: Contestant.cpp Contestant.h
	g++ -std=c++11 -c Contestant.cpp

Race.o: Race.cpp Race.h
	g++ -std=c++11 -c Race.cpp

Coordinator.o: Coordinator.cpp Coordinator.h
	g++ -std=c++11 -c Coordinator.cpp

driver.o: driver.cpp Contestant.h Race.h Files.h
	g++ -std=c++11 -c driver.cpp

# Files to remove
clean:
	rm Contestant.o Coordinator.o Race.o driver.o
	rm prog
