CC=gcc
CFLAGS= -std=gnu99 -Wall -g #-DDEBUG
ODIR=./obj
SRC=./src
BIN=./bin

EXECS = $(BIN)/myshell

LIBS =

all: $(EXECS)

$(BIN)/myshell: $(SRC)/myshell.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -rf *~ core* $(BIN)/*


