#include <stdio.h>
#include <stdlib.h>
#include "singlylinkedlist.h"

void die(const char *message)
{
	perror(message);
	exit(1);
}

int sameInt(const void *a, const void *b) {
	return (*(int *)a == *(int *)b);
}

int main() {
  struct singlylinkedlist mytestlist;
  initList(&mytestlist);

  int a[] =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  for(int i=0; i < sizeof(a)/sizeof(a[0]); ++i) {
    if(insertFront(&mytestlist, a+i) == NULL) {
    	die("insertFront failed\n");
    }
  }

  struct Node *travNode = mytestlist.head;
  while(travNode) {
    printf("%d\n", *(int *)(travNode->data));
    travNode = travNode->next;
  }

	// Testing search
	struct Node *searchedNode;
	for(int i=0; i < sizeof(a)/sizeof(a[0]); ++i) {
		if((searchedNode = search(&mytestlist, (a+i), &sameInt)) == NULL)
			die("searchNode failed\n");
		printf("%d should be %d\n", *(int *)searchedNode->data, *(a+i));
	}

	// Testing popAll
  popAll(&mytestlist);

  return 0;
}
