CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -g
LIBB = ../singlylinkedlist
LIBINCLUDE = ../singlylinkedlist
CFLAGS += -I$(LIBINCLUDE)
LDFLAGS += -L$(LIBB)
LDFLAGS += -lsinglylinkedlist

hashtabletest: libhashtable.a

libhashtable.a: hashtable.o
	ar rc libhashtable.a hashtable.o
	ranlib libhashtable.a

hashtabletest.o: hashtable.h

hashtable.o:

.PHONY: clean
clean:
	rm -f *.o a.out core hashtabletest libhashtable.a

.PHONY: all
all: clean hashtabletest

.PHONY: valgrind
valgrind:
	valgrind --leak-check=yes ./hashtabletest
