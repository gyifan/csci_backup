# compiler
CC = gcc

# compilation flags
CFLAGS = -g -Wall

EXE = over1 over2 over3 over4

all: $(EXE)

over1: over1.c Makefile
	$(CC) $< $(CFLAGS) -o over1

over2: over2.c Makefile
	$(CC) $< $(CFLAGS) -o over2

over3: over3.c Makefile
	$(CC) $< $(CFLAGS) -o over3

over4: over4.c Makefile
	$(CC) $< $(CFLAGS) -o over4

concat: concat.c Makefile
	$(CC) $< $(CFLAGS) -o concat

decoding: decoding.c Makefile
	$(CC) $< $(CFLAGS) -o decoding

clean:
	/bin/rm -f *~ *.o core* $(EXE)
