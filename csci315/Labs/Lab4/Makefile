# CSCI 315 - Operating System
# Lab4 - Makefile
# Yifan Ge
# 2/7/2013

CC=gcc
CFLAGS= -std=gnu99 -Wall
ODIR=./obj
SRC=./src
BIN=./bin

EXECS = $(BIN)/summation $(BIN)/char-threads $(BIN)/mytime

LIBS = -lm -lpthread

all: $(EXECS)

$(BIN)/summation: $(SRC)/summation.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BIN)/char-threads: $(SRC)/char-threads.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BIN)/mytime: $(SRC)/mytime.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *~ core* $(BIN)/*

