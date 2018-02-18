CC = gcc
INCLUDES =
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS =

mystacktest: libmystack.a

libmystack.a: mystack.o
	ar rc libmystack.a mystack.o
	ranlib libmystack.a

mystacktest.o: mystack.h

mystack.o:

.PHONY: clean
clean:
	rm -f *.o a.out core mystacktest libmystack.a

.PHONY: all
all: clean mystacktest

.PHONY: valgrind
valgrind:
	valgrind --leak-check=yes ./mystacktest
