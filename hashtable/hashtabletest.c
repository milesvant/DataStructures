#include <stdio.h>
#include <stdlib.h>
#include "hashtable.c"

void die(const char *message) {
  perror(message);
  exit(1);
}

int main() {
  struct HashTable *mytable = NULL;
  initHashTable(mytable);
  int keys[] = { 1, 2, 3 };
  int vals[] = { 4, 5, 6 };
  for(int i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i) {
    chainedinsert(mytable, keys[i], (vals + i));
  }
  return 0;
}
