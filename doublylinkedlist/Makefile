CC = gcc
INCLUDES =
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS =

dlltest: dlltest.o doublylinkedlist.o

libdoublylinkedlist.a: doublylinkedlist.o
	ar rc libdoublylinkedlist.a doublylinkedlist.o
	ranlib libdoublylinkedlist.a

doublylinkedlist.o: doublylinkedlist.h

dlltest.o: doublylinkedlist.h

.PHONY: clean
clean:
	rm -f *.o a.out core dlltest libdoublylinkedlist.a

.PHONY: all
all: clean dlltest libdoublylinkedlist.a
