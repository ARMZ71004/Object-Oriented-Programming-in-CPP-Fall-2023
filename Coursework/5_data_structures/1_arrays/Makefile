# executable file to create and its dependancies
prog : driver.o array.o
	g++ -std=c++11 -o prog driver.o array.o

# file dependencies
driver.o : array.h
	g++ -std=c++11 -c driver.cpp
array.o : array.h
	g++ -std=c++11 -c array.cpp

# files to remove
clean:
	rm driver.o array.o
	rm prog
