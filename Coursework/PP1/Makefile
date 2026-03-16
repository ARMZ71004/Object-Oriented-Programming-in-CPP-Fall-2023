# executable file to create and its dependancies
prog : p2.o functions.o
	g++ -std=c++11 -o prog p2.o functions.o

# file dependencies
p2.o : functions.h
	g++ -std=c++11 -c p2.cpp
functions.o : functions.h
	g++ -std=c++11 -c functions.cpp

# files to remove
clean:
	del p2.o functions.o
	del prog
