CC = clang
INCLUDES =
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS =

slltest: slltest.o SinglyLinkedList.o

libsinglylinkedlist.a: SinglyLinkedList.o
	ar rc libsinglylinkedlist.a SinglyLinkedList.o
	ranlib libsinglylinkedlist.a

SinglyLinkedList.o: SinglyLinkedList.h

slltest.o: SinglyLinkedList.h

.PHONY: clean
clean:
	rm -f *.o a.out core slltest

.PHONY: all
all: clean slltest libsinglylinkedlist.a
