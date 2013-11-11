# Makefile for CSCI 206 Computer Organization & Programming, Lab 1 
# Author: L. Felipe Perrone
# Date: 2011-08-29
#
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
#

CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

EXECS = list_test

all: $(EXECS)

doc:
	doxygen

$(OBJ)/snode.o: snode.h snode.c
	$(CC) $(CFLAGS) -c snode.c -o snode.o

$(OBJ)/slist.o: slist.h slist.c snode.h
	$(CC) $(CFLAGS) -c slist.c -o slist.o

list_test: list_test.c snode.o slist.o
	$(CC) $(CFLAGS) snode.o slist.o list_test.c -o list_test

.PHONY: clean
clean:
	/bin/rm -rf $(EXECS) *.o 

