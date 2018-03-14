#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RedBlackTree.h"
#define MAX_INT_SIZE 16

/*
 * Exit with error message
 */
void die(const char *message) {
  perror(message);
  exit(1);
}

int compareInt(const void *a, const void *b) {
  int aint = *(int *)a;
  int bint = *(int *)b;
  if(aint > bint)
    return 1;
  else if(aint == bint)
    return 0;
  else
    return -1;
}

char *intToString(const void *a) {
  char *res = malloc(MAX_INT_SIZE * sizeof(char));
  sprintf(res, "%d", *(int *)a);
  return res;
}

int main()
{
  struct RBT testTree;
  initRBT(&testTree);

  // Test insertRBNode
  int treevals[] = { 1, 2, 3, 4, 5, 6 };
  for(int i=0; i < sizeof(treevals)/sizeof(treevals[0]); ++i) {
    if(insertRBNode(&testTree, treevals + i, &compareInt) == NULL)
      die("insertRBNode failed\n");
  }

  // Test lookup
  for(int i=0; i < sizeof(treevals)/sizeof(treevals[0]); ++i) {
    if(lookup(&testTree, treevals + i, &compareInt) == NULL)
      die("lookup failed\n");
    else
      printf("Succesful lookup of %d\n", treevals[i]);
  }
  // lookup values not in the tree
  int notintree[] = { 7, 8, 9, 10, 11 };
  for(int i=0; i < sizeof(notintree)/sizeof(notintree[0]); ++i) {
    if(lookup(&testTree, notintree + i, &compareInt) != NULL)
      die("lookup failed\n");
  }

  printf("%s\n", RBTtoString(&testTree, &intToString));

  return 0;
}
