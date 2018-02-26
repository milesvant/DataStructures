#include <stdio.h>
#include <stdlib.h>
#include "hashtable.c"

int easyhash(void *val) {
  int k = *(int *)val;
  return ((k * (k + 3)) % 53);
}

int main() {
  struct Hashtable *mytable;
  initHashTable(mytable, &easyhash);
  return 0;
}
