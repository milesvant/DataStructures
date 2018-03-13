CC = clang
INCLUDES =
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS =

dlltest: dlltest.o DoublyLinkedList.o

libdoublylinkedlist.a: DoublyLinkedList.o
	ar rc libdoublylinkedlist.a DoublyLinkedList.o
	ranlib libdoublylinkedlist.a

DoublyLinkedList.o: DoublyLinkedList.h

dlltest.o: DoublyLinkedList.h

.PHONY: clean
clean:
	rm -f *.o a.out core dlltest libDoublyLinkedList.a

.PHONY: all
all: clean dlltest libdoublylinkedlist.a
