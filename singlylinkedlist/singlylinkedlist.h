#ifndef _SINGLYLINKEDLIST_H_
#define _SINGLYLINKEDLIST_H_

struct Node {
  void *data;
  struct Node *next;
};

struct singlylinkedlist {
  struct Node *head;
};

static inline void initList(struct singlylinkedlist *list) {
  list->head = NULL;
}

/*
 * inserts a Node containing data to the front of *list
 * returns the Node created if succesful and NULL on failure
 */
struct Node *insertFront(struct singlylinkedlist *list, void *data);

/*
 * removes and frees the head of *list and returns its data
 */
void *popFront(struct singlylinkedlist *list);

/*
 * searches *list for a Node containing data, then returns it
 * returns NULL if no Node containing data is found
 */
struct Node *search(struct singlylinkedlist *list, void *data,
    int (*)(const void *, const void *));

/*
 * removes and frees all Nodes in *list
 */
void popAll(struct singlylinkedlist *list);


/*
 * Adds a DNode containing data to list after prev (assumed to be in list), in
 * returns the newly created DNode
 */
struct Node *addafter(struct singlylinkedlist *list, struct Node *prev, void *data);

#endif
