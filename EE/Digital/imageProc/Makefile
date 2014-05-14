CC       = gcc
HDRS     = bmp-utl.h # add your header files here when needed
BMPOBJ   = bmp-utl.o
WRPOBJ   = wrappers.o
LISTOBJ  = list.o
OBJS     = test.o $(BMPOBJ) $(WRPOBJ) $(LISTOBJ)
CFLAGS   = -Wall -g
EXECS    = test

LFLAGS   = # add your loader flags when needed

all: $(EXECS)

# The following line will compile all *.c code to corresponding *.o file
%.o: %.c $(HDRS)
	$(CC) -c $(CFLAGS) $<

test: $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	/bin/rm -f $(OBJS) $(EXECS) core* *~ semantic.cache
