#include <stdio.h>
#include <stdlib.h>
#include "hashtable.c"

void die(const char *message) {
  perror(message);
  exit(1);
}

int compareints(const void *x, const void *y) {
  return (*(int *)x == *(int *)y);
}

int main() {

  struct HashTable mytable;
  initHashTable(&mytable);
  int keys[] = { 1, 2, 3 };
  int vals[] = { 4, 5, 6 };

  // Testing chainedinsert
  for(int i=0; i < sizeof(keys)/sizeof(keys[0]); ++i) {
    chainedinsert(&mytable, (keys+i), (vals + i));
  }

  // Testing chainedsearch
  printf("Testing chainedsearch\n");
  int searchfor[] = { 1, 2, 3, 4, 5, 6 };
  for(int i=0; i < sizeof(searchfor)/sizeof(searchfor[0]); ++i) {
    void *result = chainedsearch(&mytable, (searchfor + i), &compareints);
    if(result) { // Found key in table
      int val = *(int *)result;
      printf("Found: [%d -> %d]\n", searchfor[i], val);
    }
    else { // Key not found in table
      printf("Key %d not found in table\n", searchfor[i]);
    }
  }

  // Testing chaineddelete
  printf("Testing chaineddelete\n");
  for(int i=0; i < sizeof(searchfor)/sizeof(searchfor[0]); ++i) {
    void *result = chaineddelete(&mytable, (searchfor + i), &compareints);
    if(result) { // Found key in table
      int val = *(int *)result;
      printf("Deleted [%d -> %d]\n", searchfor[i], val);
    }
    else { // Key not found in table
      printf("Key %d not found in table\n", searchfor[i]);
    }
  }

  for(int i=0; i < sizeof(searchfor)/sizeof(searchfor[0]); ++i) {
    void *result = chainedsearch(&mytable, (searchfor + i), &compareints);
    if(result) { // Found key in table
      int val = *(int *)result;
      printf("Found: [%d -> %d]\n", searchfor[i], val);
    }
    else { // Key not found in table
      printf("Key %d not found in table\n", searchfor[i]);
    }
  }

  // Testing deleteall
  printf("Testing deleteall\n");
  for(int i=0; i < sizeof(keys)/sizeof(keys[0]); ++i) {
    chainedinsert(&mytable, (keys+i), (vals + i));
  }

  deleteall(&mytable);

  for(int i=0; i < sizeof(searchfor)/sizeof(searchfor[0]); ++i) {
    void *result = chainedsearch(&mytable, (searchfor + i), &compareints);
    if(result) { // Found key in table
      int val = *(int *)result;
      printf("Found: [%d -> %d]\n", searchfor[i], val);
    }
    else { // Key not found in table
      printf("Key %d not found in table\n", searchfor[i]);
    }
  }

  return 0;
}
