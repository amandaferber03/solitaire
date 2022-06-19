CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

solitaire: main.o Table.o Game.o CreatePiece.o 
	$(CC) -o solitaire main.o Table.o Game.o CreatePiece.o

Table.o: Table.cpp Card.h CreatePiece.h	Ace.h Two.h Three.h Four.h Five.h Six.h Seven.h Eight.h Nine.h Ten.h Jack.h Queen.h King.h
	$(CC) -c Table.cpp $(CFLAGS)
Game.o: Game.cpp Table.h Game.h Card.h
	$(CC) -c Game.cpp $(CFLAGS)
CreatePiece.o: CreatePiece.cpp Table.h Game.h Card.h Ace.h Two.h Three.h Four.h Five.h Six.h Seven.h Eight.h Nine.h Ten.h Jack.h Queen.h King.h
	$(CC) -c CreatePiece.cpp $(CFLAGS)
main.o: main.cpp Table.h Game.h Card.h Ace.h Two.h Three.h Four.h Five.h Six.h Seven.h	Eight.h	Nine.h Ten.h Jack.h Queen.h King.h
	$(CC) -c main.cpp $(CFLAGS)
.PHONY: clean all
clean:
	rm -f *.o solitaire
