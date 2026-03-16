# executable file to create and its dependancies
prog : driver.o Node.o List.o Iterator.o
	g++ -std=c++11 -o prog driver.o Node.o List.o Iterator.o

# file dependencies
driver.o : Node.h
	g++ -std=c++11 -c driver.cpp
Node.o : Node.h 
	g++ -std=c++11 -c Node.cpp
List.o : Node.h List.h
	g++ -std=c++11 -c List.cpp
Iterator.o : Node.h Iterator.h
	g++ -std=c++11 -c Iterator.cpp
# files to remove
clean:
	rm driver.o Node.o List.o Iterator.o
	rm prog