CC = gcc
INCLUDES = -I ../singlylinkedlist/
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g -L../singlylinkedlist/
LDLIBS =

hashtabletest: libhashtable.a

libhashtable.a: hashtable.o
	ar rc libhashtable.a hashtable.o
	ranlib libhashtable.a

hashtabletest.o: hashtable.h ../singlylinkedlist/singlylinkedlist.h

hashtable.o: ../singlylinkedlist/libsinglylinkedlist.a

.PHONY: clean
clean:
	rm -f *.o a.out core hashtabletest libhashtable.a

.PHONY: all
all: clean hashtabletest

.PHONY: valgrind
valgrind:
	valgrind --leak-check=yes ./hashtabletest
