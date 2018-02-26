CC = gcc
INCLUDES =
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS =

libsinglylinkedlist.a: singlylinkedlist.o
	ar rc libhashtable.a hashtable.o
	ranlib libhashtable.a

singlylinkedlist.o: singlylinkedlist.h

.PHONY: clean
clean:
	rm -f *.o a.out core libsinglylinkedlist.a

.PHONY: all
all: clean libsinglylinkedlist.a
