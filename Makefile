all: main enemy.o

main: main.cpp enemy.o
	g++ -Wall main.cpp enemy.o -o main

enemy.o: enemy.cpp enemy.h
	g++ -Wall enemy.cpp enemy.h -c

clean:
	rm enemy.o main enemy.h.gch