CC = clang
INCLUDES =
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS =

rbbtest: RedBlackTree.o

libredblacktree.a: RedBlackTree.o
	ar rc libredblacktree.a RedBlackTree.o
	ranlib libredblacktree.a

RedBlackTree.o:

rbbtest.o:

.PHONY: clean
clean:
	rm -f *.o a.out libredblacktree.a rbbtest

.PHONY: all
all: clean libredblacktree.a rbbtest
