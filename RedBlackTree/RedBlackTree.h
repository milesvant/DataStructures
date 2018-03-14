#ifndef _REDBLACKTREE_H
#define _REDBLACKTREE_H

struct RBNode {
  void *value;
  struct RBNode *leftchild;
  struct RBNode *rightchild;
  struct RBNode *parent;
  int color; // Black is 0, Red is 1
};

struct RBT {
  struct RBNode *root;
};

static inline void initRBT(struct RBT *mytree) {
  mytree->root = NULL;
}

/*
 * Inserts a RBNode with value into mytree, then returns that RBNode. Returns
 * NULL if a RBNode with that value already exists inside mytree. The compar(a, b)
 * function should return <0 if a < b, 0 if a = b, and >0 if a > b.
 */
struct RBNode *insertRBNode(struct RBT *mytree, void *value,
  int (*compar)(const void *, const void *));

/*
 * Looks up a value in a RBT, then returns the RBNode containing that value if
 * one exists, and NULL otherwise. The compar(a, b) function should return <0 if
 * a < b, 0 if a = b, and >0 if a > b.
 */
struct RBNode *lookup(struct RBT *mytree, void *value,
  int (*compar)(const void *, const void *));

void *deleteRBNode(struct RBT *mytree, void *value,
  int (*)(const void *, const void *));

char *RBTtoString(struct RBT *mytree, char *(*valToString)(const void *));

#endif
