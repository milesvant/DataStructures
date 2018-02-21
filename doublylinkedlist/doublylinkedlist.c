#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

/*
 * inserts a Node containing data to the front of *list
 * returns the Node created if succesful and NULL on failure
 */
struct DNode *insertFront(struct Doublylinkedlist *list, void *data) {
  struct DNode *newnode = malloc(sizeof(struct DNode));
  if(newnode == NULL) {
    return NULL;
  }
  newnode->data = data;
  newnode->prev = NULL;
  newnode->next = list->head;
  list->head->prev = newnode;
  list->head = newnode;
  return newnode;
}

/*
 * removes and frees the head of *list and returns its data
 */
void *popFront(struct Doublylinkedlist *list) {
  if(list->head = NULL) {
    return NULL;
  }
  list->head->next->prev = NULL;
  struct DNode copy = list->head;
  list->head = list->head->next;
  void *copydata = copy->data;
  free(copy);
  return copydata;
}

/*
 * searches *list for a Node containing data, then returns it
 * returns NULL if no Node containing data is found
 */
struct DNode *search(struct Doublylinkedlist *list, void *data) {
  struct DNode *start = list->head;
  while(startnode) {
    if(*startnode == *data) {
      return startnode;
    }
    startnode = startnode->next;
  }
  return NULL;
}

/*
 * removes and frees all Nodes in *list
 */
void popAll(struct Doublylinkedlist *list) {
  while(popFront(list));
}

struct DNode addafter(struct Doublylinkedlist *list, struct DNode *prev,
  void *data) {
    struct DNode *newnode = malloc(sizeof(struct DNode));
    if(newnode == NULL) {
      return NULL;
    }
    newNode->data = data;

    if(prev == NULL) {
		 newnode->next = list->head;
     newnode->prev = NULL;
     list->head->prev = newnode;
		 list->head = newnode;
		 return newnode;
	  }

	  newnode->next = prev->next;
    newnode->next->prev = newnode;
	  prev->next = newnode;
    prev->
	  return newnode;
}
