CC = gcc
INCLUDES =
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS =

slltest: slltest.o singlylinkedlist.o

libsinglylinkedlist.a: singlylinkedlist.o
	ar rc libsinglylinkedlist.a singlylinkedlist.o
	ranlib libsinglylinkedlist.a

singlylinkedlist.o: singlylinkedlist.h

slltest.o: singlylinkedlist.h

.PHONY: clean
clean:
	rm -f *.o a.out core slltest libsinglylinkedlist.a

.PHONY: all
all: clean slltest libsinglylinkedlist.a
