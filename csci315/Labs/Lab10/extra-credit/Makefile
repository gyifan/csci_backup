
CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g -DDEBUG

INC = ./include
SRC = ./src
OBJ = ./obj
DOC = ./doc
BIN = ./bin

POLICY = -DWORSTFIT #-DWORSTFIT -DFIRSTFIT -DBESTFIT

vpath %.h ./include
vpath %.c ./src

EXECS = readlinetest dlisttest memory-test

all: $(EXECS)

doc:
	doxygen

$(OBJ)/dnode.o: dnode.h dnode.c
	$(CC) $(CFLAGS) -c $(SRC)/dnode.c -o $(OBJ)/dnode.o

$(OBJ)/dlist.o: dlist.h dlist.c dnode.h
	$(CC) $(CFLAGS) -c $(SRC)/dlist.c -o $(OBJ)/dlist.o

dlisttest: $(SRC)/dlisttest.c $(OBJ)/dnode.o $(OBJ)/dlist.o
	$(CC) $(CFLAGS) $(OBJ)/dnode.o $(OBJ)/dlist.o $(SRC)/dlisttest.c -o $(BIN)/dlisttest

$(OBJ)/allocator.o: allocator.h allocator.c
	$(CC) $(CFLAGS) -c $(SRC)/allocator.c -o $(OBJ)/allocator.o $(POLICY)

memory-test: $(SRC)/memory-test.c $(OBJ)/allocator.o
	$(CC) $(CFLAGS) $(OBJ)/allocator.o $(OBJ)/dnode.o $(OBJ)/dlist.o $(SRC)/memory-test.c -o $(BIN)/memory-test $(POLICY)

$(OBJ)/readline.o: $(INC)/readline.h $(SRC)/readline.c
	$(CC) $(CFLAGS) -c $(SRC)/readline.c -o $(OBJ)/readline.o

readlinetest: $(SRC)/readlinetest.c $(OBJ)/readline.o
	$(CC) $(CFLAGS) $(OBJ)/readline.o $(SRC)/readlinetest.c -o $(BIN)/readlinetest

.PHONY: clean
clean:
	/bin/rm -rf $(BIN)/* $(OBJ)/* $(DOC)/* core* *~

