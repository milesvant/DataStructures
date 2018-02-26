#ifndef _SINGLYLINKEDLIST_H_
#define _SINGLYLINKEDLIST_H_

struct Node {
  void *data;
  struct Node *next;
};

struct Singlylinkedlist {
  struct Node *head;
};

static inline void initList(struct Singlylinkedlist *list) {
  list->head = NULL;
}

/*
 * inserts a Node containing data to the front of *list
 * returns the Node created if succesful and NULL on failure
 */
struct Node *insertFront(struct Singlylinkedlist *list, void *data);

/*
 * removes and frees the head of *list and returns its data
 */
void *popFront(struct Singlylinkedlist *list);

/*
 * searches *list for a Node containing data, then returns it
 * returns NULL if no Node containing data is found
 */
struct Node *search(struct Singlylinkedlist *list, void *data, int (*compar)(void *, void *));

/*
 * removes and frees all Nodes in *list
 */
void popAll(struct Singlylinkedlist *list);

/*
 * searches for the first node with data equal to data, then deletes it
 * and returns it. Returns NULL if no Node containing data is found
 */
void deleteNode(struct Singlylinkedlist *list, void *data, int (*compar)(void *, void *));

#endif
