#include <stdio.h>
#include <stdlib.h>
#include "singlylinkedlist.h"

struct Node *insertFront(struct Singlylinkedlist *list, void *data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if(newNode == NULL) {
    return NULL;
  }
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
  return newNode;
}

void *popFront(struct Singlylinkedlist *list) {
  if(list->head == NULL) {
    return NULL;
  }
  void *returndata = list->head->data;
  struct Node *newhead = list->head;
  list->head = newhead;
  free(newhead);
  return returndata;
}

struct Node *search(struct Singlylinkedlist *list, void *data, 
		int (*compar)(void *, void *)) {
  struct Node *start = list->head;
  while(start) {
    if(compar(start->data, data)) {
      return start;
    }
    start = start->next;
  }
  return NULL;
}

void popAll(struct Singlylinkedlist *list) {
  while(popFront(list));
}

void *deleteNode(struct Singlylinkedlist *list, void *data, 
		int (*compar)(void *, void *)) {
  struct Node *myNode = list->head;
  struct Node *prev = NULL;
  while(myNode) {
    if(compar(myNode->data, data)) {
      prev->next = myNode->next;
      free(myNode);
      break;
    }
    prev = myNode;
    myNode = myNode->next;
  }
}
