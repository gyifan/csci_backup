CC=gcc
CFLAGS= -std=gnu99 -Wall -g #-DDEBUG
ODIR=./obj
SRC=./src
BIN=./bin
LIBS=

EXECS = $(BIN)/echod $(BIN)/echoreq

all: $(EXECS)

$(BIN)/echod: $(SRC)/echod.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BIN)/echoreq: $(SRC)/echoreq.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core* $(BIN)/*


