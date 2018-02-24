#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_

struct DNode {
  void *data;
  struct DNode *next;
  struct DNode *prev;
};

struct Doublylinkedlist {
  struct DNode *head;
};

static inline void initList(struct Doublylinkedlist *list) {
  list->head = NULL;
}

/*
 * inserts a Node containing data to the front of *list
 * returns the Node created if succesful and NULL on failure
 */
struct DNode *insertFront(struct Doublylinkedlist *list, void *data);

/*
 * removes and frees the head of *list and returns its data
 */
void *popFront(struct Doublylinkedlist *list);

/*
 * searches *list for a Node containing data, then returns it
 * returns NULL if no Node containing data is found
 */
struct DNode *search(struct Doublylinkedlist *list, void *data);

/*
 * removes and frees all Nodes in *list
 */
void popAll(struct Doublylinkedlist *list);

/*
 * Adds a DNode containing data to list after prev (assumed to be in list), in
 * returns the newly created DNode
 */
struct DNode addafter(struct Doublylinkedlist *list, struct DNode *prev, void *data);

#endif
