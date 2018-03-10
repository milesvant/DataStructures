#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

/*
 * inserts a Node containing data to the front of *list
 * returns the Node created if succesful and NULL on failure
 */
struct DNode *insertFront(struct doublylinkedlist *list, void *data) {
  struct DNode *newnode = malloc(sizeof(struct DNode));
  if(newnode == NULL) {
    return NULL;
  }

  newnode->data = data;
  newnode->prev = NULL;
  newnode->next = list->head;
  if(list->head) {
    list->head->prev = newnode;
  }
  list->head = newnode;
  return newnode;
}

/*
 * removes and frees the head of *list and returns its data
 */
void *popFront(struct doublylinkedlist *list) {
  if(list->head == NULL) {
    return NULL;
  }
  if(list->head->next) {
    list->head->next->prev = NULL;
  }
  struct DNode *copy = list->head;
  list->head = list->head->next;
  void *copydata = copy->data;
  free(copy);
  return copydata;
}

/*
 * searches *list for a Node containing data, then returns it
 * returns NULL if no Node containing data is found
 */
struct DNode *search(struct doublylinkedlist *list, void *data,
    int (*compar)(const void *, const void *)) {
  struct DNode *start = list->head;
  while(start) {
    if((*compar)(start->data, data)) {
      return start;
    }
    start = start->next;
  }
  return NULL;
}

/*
 * removes and frees all Nodes in *list
 */
void popAll(struct doublylinkedlist *list) {
  while(popFront(list));
}

/*
 * Adds a DNode containing data to list after prev (assumed to be in list), in
 * returns the newly created DNode
 */
struct DNode *addAfter(struct doublylinkedlist *list, struct DNode *prev,
  void *data) {
    struct DNode *newnode = malloc(sizeof(struct DNode));
    if(newnode == NULL) {
      return NULL;
    }
    newnode->data = data;

    if(prev == NULL) {
		 newnode->next = list->head;
     newnode->prev = NULL;
     list->head->prev = newnode;
		 list->head = newnode;
		 return newnode;
	  }

	  newnode->next = prev->next;
    if(newnode->next)
      newnode->next->prev = newnode;
	  prev->next = newnode;
	  return newnode;
}
