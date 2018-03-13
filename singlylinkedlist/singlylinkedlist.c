#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SinglyLinkedList.h"

struct Node *insertFront(struct SinglyLinkedList *list, void *data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if(newNode == NULL) {
    return NULL;
  }
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
  return newNode;
}

void *popFront(struct SinglyLinkedList *list) {
  if(list->head == NULL) {
    return NULL;
  }
  struct Node *headPointer = list->head;
	list->head = headPointer->next;
	void *returnData = headPointer->data;
	free(headPointer);
	return returnData;
}

struct Node *search(struct SinglyLinkedList *list, void *data,
		int (*compar)(const void *, const void *)) {
  struct Node *start = list->head;
  while(start) {
    if(compar(start->data, data)) {
      return start;
    }
    start = start->next;
  }
  return NULL;
}

void popAll(struct SinglyLinkedList *list) {
  while(popFront(list));
}

/*
 * Adds a Node containing data to list after prev (assumed to be in list), in
 * returns the newly created Node
 */
struct Node *addafter(struct SinglyLinkedList *list, struct Node *prev, void *data) {
  struct Node *newNode = malloc(sizeof(struct Node));
	if(newNode == NULL) {
		return NULL;
	}
	newNode->data = data;

	if(prev == NULL) {
		newNode->next = list->head;
		list->head = newNode;
		return newNode;
	}

	newNode->next = prev->next;
	prev->next = newNode;

	return newNode;
}
