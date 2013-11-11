#
# CSCI 315 Operating Systems Design
# Author: L. Felipe Perrone
# Date: 2011-04-21
# Copyright (c) 2011 Bucknell University
#
# Permission is hereby granted, free of charge, to any individual or
# institution obtaining a copy of this software and associated
# documentation files (the "Software"), to use, copy, modify, and
# distribute without restriction, provided that this copyright and
# permission notice is maintained, intact, in all copies and supporting
# documentation.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY CLAIM, DAMAGES
# OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
# OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
# OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# compiler


CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

INC = ./include
SRC = ./src
OBJ = ./obj
DOC = ./doc
BIN = ./bin

vpath %.h ./include
vpath %.c ./src

EXECS = file_stat fdump traverse #read_dir

all: $(EXECS)

$(OBJ)/file_stat.o: file_stat.c
	$(CC) -c $(CFLAGS) $(SRC)/file_stat.c -o $(OBJ)/file_stat.o

file_stat: $(OBJ)/file_stat.o
	$(CC) $(CFLAGS) -o $(BIN)/file_stat $(OBJ)/file_stat.o

$(OBJ)/read_dir.o: read_dir.c
	$(CC) -c $(CFLAGS) $(SRC)/read_dir.c -o $(OBJ)/read_dir.o

#read_dir: $(OBJ)/read_dir.o
#	$(CC) -o $(BIN)/read_dir $(OBJ)/read_dir.o

$(OBJ)/hexdump.o: hexdump.c
	$(CC) -c $(CFLAGS) $(SRC)/hexdump.c -o $(OBJ)/hexdump.o

fdump: $(SRC)/fdump.c $(OBJ)/hexdump.o
	$(CC) $(CFLAGS) $(SRC)/fdump.c $(OBJ)/hexdump.o -o $(BIN)/fdump

traverse: traverse.c $(OBJ)/read_dir.o
	$(CC) $(CFLAGS) $(SRC)/traverse.c $(OBJ)/read_dir.o -o $(BIN)/traverse

.PHONY: clean
clean:
	/bin/rm -rf $(BIN)/* $(OBJ)/* core* *~

