SRC=Source/
BIN=bin/
INC=include/
OBJ=obj/

CC=g++
CFLAGS= -Iinclude -W -Wall -g -pedantic --std=c++11 -lm

all: main
	echo "compilation terminee"

main: main.o Index.o
	$(CC) -o $(BIN)main $(OBJ)main.o $(OBJ)index.o

recherche.o: $(SRC)recherche.cpp $(INC)recherche.h
	$(CC) -o $(OBJ)recherche.o -c $(SRC)recherche.cpp $(CFLAGS)

Index.o : $(SRC)Index.cpp $(INC)Index.h
	$(CC) -o $(OBJ)Index.o -c $(SRC)Index.cpp $(CFLAGS)

main.o: $(SRC)main.cpp $(INC)recherche.h
	$(CC) -o $(OBJ)main.o -c $(SRC)main.cpp $(CFLAGS)

clean:
	rm -rvf $(BIN)main $(OBJ)*.o $(SRC)*~ $(INC)*~

exec:
	./$(BIN)main

execfile:
	./$(BIN)main README.txt
