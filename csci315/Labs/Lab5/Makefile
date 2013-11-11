# CSCI 315 - Operating System
# Lab5 - Makefile
# Yifan Ge
# 2/16/2013

CC=gcc
CFLAGS= -std=gnu99 -Wall
ODIR=./obj
SRC=./src
BIN=./bin

EXECS = $(BIN)/timer $(BIN)/clock $(BIN)/user

LIBS =

all: $(EXECS)

$(BIN)/timer: $(SRC)/timer.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BIN)/clock: $(SRC)/clock.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BIN)/user: $(SRC)/user.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core* $(BIN)/*

