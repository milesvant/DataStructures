#ifndef _DoublyLinkedList_H_
#define _DoublyLinkedList_H_

struct DNode {
  void *data;
  struct DNode *next;
  struct DNode *prev;
};

struct DoublyLinkedList {
  struct DNode *head;
};

static inline void initList(struct DoublyLinkedList *list) {
  list->head = NULL;
}

/*
 * inserts a Node containing data to the front of *list
 * returns the Node created if succesful and NULL on failure
 */
struct DNode *insertFront(struct DoublyLinkedList *list, void *data);

/*
 * removes and frees the head of *list and returns its data
 */
void *popFront(struct DoublyLinkedList *list);

/*
 * searches *list for a Node containing data, then returns it
 * returns NULL if no Node containing data is found
 */
struct DNode *search(struct DoublyLinkedList *list, void *data,
  int (*)(const void *, const void *));

/*
 * removes and frees all Nodes in *list
 */
void popAll(struct DoublyLinkedList *list);

/*
 * Adds a DNode containing data to list after prev (assumed to be in list), in
 * returns the newly created DNode
 */
struct DNode *addAfter(struct DoublyLinkedList *list, struct DNode *prev, void *data);

/*
 * Returns a string representation of the singlylinkedlist at address list, using
 * an inputted function to convert data into strings
 */
char *sllToString(const struct DoublyLinkedList *list,
    char *(*dataString)(void *));

#endif
