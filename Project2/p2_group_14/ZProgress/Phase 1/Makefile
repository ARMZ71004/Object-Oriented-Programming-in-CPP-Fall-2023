# Executable file to create and its dependencies
prog: Contestant.o Race.o driver.o
	g++ -std=c++11 -o prog Contestant.o Race.o driver.o

# File dependencies
Contestant.o: Contestant.cpp Contestant.h
	g++ -std=c++11 -c Contestant.cpp

Race.o: Race.cpp Race.h
	g++ -std=c++11 -c Race.cpp

driver.o: driver.cpp Contestant.h Race.h Files.h
	g++ -std=c++11 -c driver.cpp

# Files to remove
clean:
	rm Contestant.o Race.o driver.o
	rm prog
