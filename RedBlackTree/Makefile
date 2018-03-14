CC = clang
INCLUDES =
CFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS =

libredblacktree.a: RedBlackTree.o
	ar rc libredblacktree.a RedBlackTree.o
	ranlib libredblacktree.a

RedBlackTree.o:

.PHONY: clean
clean:
	rm -f *.o a.out libredblacktree.a

.PHONY: all
all: clean libredblacktree.a
