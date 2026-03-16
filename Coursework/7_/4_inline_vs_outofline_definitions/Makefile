# executable file to create and its dependancies
prog : driver.o Course.o
	g++ -std=c++11 -o prog driver.o Course.o

# file dependencies
driver.o : Course.h
	g++ -std=c++11 -c driver.cpp
Course.o : Course.h
	g++ -std=c++11 -c Course.cpp

# files to remove
clean:
	rm driver.o Course.o
	rm prog
