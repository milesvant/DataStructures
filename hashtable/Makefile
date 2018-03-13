CC = clang
CFLAGS = -g -Wall
LDFLAGS = -g
LIBB = ../SinglyLinkedList
LIBINCLUDE = ../SinglyLinkedList
CFLAGS += -I$(LIBINCLUDE)
LDFLAGS += -L$(LIBB)
LDFLAGS += -lsinglylinkedlist

hashtabletest: libhashtable.a

libhashtable.a: HashTable.o
	ar rc libhashtable.a HashTable.o
	ranlib libhashtable.a

hashtabletest.o: hashtable.h

HashTable.o:

.PHONY: clean
clean:
	rm -f *.o a.out core hashtabletest libhashtable.a

.PHONY: all
all: clean hashtabletest

.PHONY: valgrind
valgrind:
	valgrind --leak-check=yes ./hashtabletest
