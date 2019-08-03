# CC = gcc
# CFLAGS = -ansi -pedantic -Wall -g
# adjust: adjust.o grades.o
# 	$(CC) $(CFLAGS) -o adjust adjust.o grades.o

# adjust.o: adjust.c grades.h
# 	$(CC) $(CFLAGS) -c adjust.c

# grades.o: grades.c grades.h
# 	$(CC) $(CFLAGS) -c grades.c


IDIR =.
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=new
LDIR =../lib

LIBS=-lm

_DEPS = grades.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = adjust.o grades.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o hellomake 
