CC=gcc
CFLAGS= -std=gnu99 -Wall -g #-DDEBUG
ODIR=./obj
SRC=./src
BIN=./bin

LIBS = -lpthread

EXECS = $(BIN)/dp $(BIN)/problem1 $(BIN)/problem2 $(BIN)/problem3-1 $(BIN)/problem3-2

all: $(EXECS)

$(BIN)/dp: $(SRC)/dp.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BIN)/problem1: $(SRC)/problem1.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BIN)/problem2: $(SRC)/problem2.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BIN)/problem3-1: $(SRC)/problem3-1.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BIN)/problem3-2: $(SRC)/problem3-2.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core* $(BIN)/*


