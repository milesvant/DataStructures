#ifndef _SinglyLinkedList_H_
#define _SinglyLinkedList_H_

struct Node {
  void *data;
  struct Node *next;
};

struct SinglyLinkedList {
  struct Node *head;
};

static inline void initList(struct SinglyLinkedList *list) {
  list->head = NULL;
}

/*
 * inserts a Node containing data to the front of *list
 * returns the Node created if succesful and NULL on failure
 */
struct Node *insertFront(struct SinglyLinkedList *list, void *data);

/*
 * removes and frees the head of *list and returns its data
 */
void *popFront(struct SinglyLinkedList *list);

/*
 * searches *list for a Node containing data, then returns it
 * returns NULL if no Node containing data is found
 */
struct Node *search(struct SinglyLinkedList *list, void *data,
    int (*)(const void *, const void *));

/*
 * removes and frees all Nodes in *list
 */
void popAll(struct SinglyLinkedList *list);


/*
 * Adds a DNode containing data to list after prev (assumed to be in list), in
 * returns the newly created DNode
 */
struct Node *addafter(struct SinglyLinkedList *list, struct Node *prev, void *data);

/*
 * Returns a string representation of the SinglyLinkedList at address list, using
 * an inputted function to convert data into strings
 */
char *sllToString(const struct SinglyLinkedList *list, char *(*)(void *));

#endif
