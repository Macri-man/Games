all: game

game: main.o
	gcc main.o -o game

main.o: main.c
	gcc -c main.c

clean:
	rm -rf *o game