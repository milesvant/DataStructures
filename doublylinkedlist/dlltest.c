#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

void die(const char *message)
{
	perror(message);
	exit(1);
}

int sameInt(const void *a, const void *b) {
	return (*(int *)a == *(int *)b);
}

void printList(struct DoublyLinkedList *mylist) {
  struct DNode *travDNode = mylist->head;
  while(travDNode) {
    printf("%d\n", *(int *)(travDNode->data));
    travDNode = travDNode->next;
  }
}

int main()
{
  struct DoublyLinkedList mytestlist;
  initList(&mytestlist);

  int a[] =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  printf("testing insertFront\n");
  for(int i=0; i < sizeof(a)/sizeof(a[0]); ++i) {
    if(insertFront(&mytestlist, a+i) == NULL) {
    	die("insertFront failed\n");
    }
  }

  printList(&mytestlist);

	// Testing search
  printf("\ntesting search\n");
	struct DNode *searchedDNode;
	for(int i=0; i < sizeof(a)/sizeof(a[0]); ++i) {
		if((searchedDNode = search(&mytestlist, (a+i), &sameInt)) == NULL)
			die("searchDNode failed\n");
		printf("%d -> %d\n", *(int *)searchedDNode->data, *(a+i));
	}

  // Testing addAfter
  printf("\ntesting addafter\n");
  struct DNode *afterNode = addAfter(&mytestlist, mytestlist.head, (a+1));
  afterNode = addAfter(&mytestlist, search(&mytestlist, (a+5), &sameInt), (a+1));
  afterNode = addAfter(&mytestlist, search(&mytestlist, (a+0), &sameInt), (a+0));
  printList(&mytestlist);

	// Testing popAll
  printf("testing popAll\n");
  popAll(&mytestlist);

  return 0;
}
