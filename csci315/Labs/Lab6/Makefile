#
# Copyright (c) 2012 Bucknell University
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation;
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#
# Author: L. Felipe Perrone (perrone@bucknell.edu)
#

CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

INC = ./include
SRC = ./src
OBJ = ./obj
DOC = ./doc
BIN = ./bin

LIBS = -lpthread -lrt

vpath %.h ./include
vpath %.c ./src

EXECS =	solution adt-test

all: $(EXECS)

doc:
	doxygen

$(OBJ)/circular-list.o: $(INC)/circular-list.h $(SRC)/circular-list.c 
	$(CC) $(CFLAGS) -c $(SRC)/circular-list.c -o $(OBJ)/circular-list.o $(LIBS)

solution: $(OBJ)/circular-list.o
	$(CC) $(CFLAGS) $(SRC)/solution.c $(OBJ)/circular-list.o -o $(BIN)/solution $(LIBS)

adt-test: $(OBJ)/circular-list.o $(SRC)/adt-test.c
	$(CC) $(CFLAGS) $(SRC)/adt-test.c $(OBJ)/circular-list.o -o $(BIN)/adt-test $(LIBS)

.PHONY: clean
clean:
	/bin/rm -f $(BIN)/* core* *~
	/bin/rm -f ./obj/*
	/bin/rm -f ./doc/*
	/bin/rm -f ./include/*~
	/bin/rm -f ./src/*~

