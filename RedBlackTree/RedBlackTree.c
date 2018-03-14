#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RedBlackTree.h"
#define MAX_STRING_SIZE 1000

/*
 * Exit with error message
 */
static void die(const char *message) {
  perror(message);
  exit(1);
}

/*
 * Creates a node with given value and color (0 for black, 1 for red), then
 * return the created node.
 */
static struct RBNode *createNode(struct RBNode *childof, void *value, int color) {
  struct RBNode *newNode = malloc(sizeof(struct RBNode));
  if(newNode == NULL)
    die("error: malloc failed\n");
  newNode->leftchild = NULL;
  newNode->rightchild = NULL;
  newNode->value = value;
  newNode->color = color;
  newNode->parent = childof;
  return newNode;
}

/*
 * Returns 1 if mynode is a left child, 0, if mynode is a right child, and -1
 * if mynode has no parent.
 */
static int isLeftChild(struct RBNode *mynode) {
  if(mynode->parent)
    return (mynode->parent->leftchild == mynode);
  return -1;
}

/*
 * Returns mynode's grandparent, or NULL if mynode does not have one.
 */
static struct RBNode *grandparent(struct RBNode *mynode) {
  if(mynode) {
    if(mynode->parent)
      return mynode->parent->parent;
  }
  return NULL;
}

/*
 * Returns mynode's uncle, or NULL if mynode does not have one.
 */
static struct RBNode *uncle(struct RBNode *mynode) {
  struct RBNode *gp = grandparent(mynode);
  if(gp) {
    if(isLeftChild(mynode->parent))
      return gp->rightchild;
    return gp->leftchild;
  }
  return NULL;
}

struct RBNode *insertRBNode(struct RBT *mytree, void *value,
  int (*compar)(const void *, const void *)) {
    if(mytree->root == NULL) // Tree is empty
      return (mytree->root = createNode(NULL, value, 0));
    struct RBNode *currentNode = mytree->root;
    struct RBNode *parent = NULL;

    // Naive BST insert
    int right = 0;
    while(currentNode) {
      int comparison = compar(value, currentNode->value);
      parent = currentNode;
      if(comparison == 0)
        return NULL;
      right = (comparison > 0);
      currentNode = (right ? currentNode->rightchild : currentNode->leftchild);
    }

    struct RBNode *newnode = createNode(parent, value, 1);
    if(right)
      parent->rightchild = newnode;
    else
      parent->leftchild = newnode;

    if(parent->color == 0) // If parent's color is black, we're done
      return newnode;

    // Restore Red-Black Tree property
    struct RBNode *gp = grandparent(newnode);
    struct RBNode *myuncle = uncle(newnode);
    // If newnode's uncle is black or NULL, restructure
    if((myuncle == NULL) || (myuncle->color == 0)) {
      int cl = isLeftChild(newnode);
      int pl = isLeftChild(parent);
      if(gp) { // Grandparent and uncle both exist
        if(cl && pl) { // Left child and left parent
          if(gp->parent) {
            if(isLeftChild(gp))
              gp->parent->leftchild = parent;
            else
              gp->parent->rightchild = parent;
            parent->parent = gp->parent;
          } else {
            mytree->root = parent;
            parent->parent = NULL;
          }
          gp->leftchild = parent->rightchild;
          parent->rightchild = gp;

          gp->color = 1;
          parent->color = 0;

          if(parent->rightchild)
            parent->rightchild->parent = gp;
          gp->parent = parent;
        }
        else if(cl && (pl == 0)) { // Left child and right parent
          if(gp->parent) {
            if(isLeftChild(gp))
              gp->parent->leftchild = newnode;
            else
              gp->parent->rightchild = newnode;
            newnode->parent = gp->parent;
          } else {
            mytree->root = newnode;
            newnode->parent = NULL;
          }
          parent->leftchild = NULL;
          gp->rightchild = NULL;
          newnode->leftchild = gp;
          newnode->rightchild = parent;

          gp->color = 1;
          newnode->color = 0;
          parent->color = 1;

          parent->parent = newnode;
          gp->parent = newnode;
        }
        else if((cl == 0) && pl) { // Right child and left parent
          if(gp->parent) {
            if(isLeftChild(gp))
              gp->parent->leftchild = newnode;
            else
              gp->parent->rightchild = newnode;
            newnode->parent = gp->parent;
          } else {
            mytree->root = newnode;
            newnode->parent = NULL;
          }
          parent->rightchild = NULL;
          gp->leftchild = NULL;
          newnode->leftchild = parent;
          newnode->rightchild = gp;

          newnode->color = 0;
          gp->color = 1;
          parent->color = 1;

          parent->parent = newnode;
          gp->parent = newnode;
        }
        else { // Right child and right parent
          if(gp->parent) {
            if(isLeftChild(gp))
              gp->parent->leftchild = parent;
            else
              gp->parent->rightchild = parent;
            parent->parent = gp->parent;
          } else {
            mytree->root = parent;
            parent->parent = NULL;
          }
          gp->rightchild = parent->leftchild;
          parent->leftchild = gp;

          gp->color = 1;
          parent->color = 0;

          if(parent->leftchild)
            parent->leftchild->parent = gp;
          gp->parent = parent;
        }
      }
    } else { // Otherwise, recolor
      parent->color = 0;
      if(gp)
        gp->color = 1;
      if(myuncle)
        myuncle->color = 0;
    }
  return newnode;
}

struct RBNode *lookup(struct RBT *mytree, void *value,
  int (*compar)(const void *, const void *)) {
    struct RBNode *currentNode = mytree->root;
    while(currentNode) {
      int comparison = compar(value, currentNode->value);
      if(comparison == 0)
        return currentNode;
      currentNode =
        (comparison > 0 ? currentNode->rightchild : currentNode->leftchild);
    }
    return NULL;
}


void *deleteRBNode(struct RBT *mytree, void *value,
  int (*compar)(const void *, const void *)) {
    void *n = NULL;
    return n;
}

char *RBTtoString(struct RBT *mytree, char *(*valToString)(const void *)) {
  char *result = malloc(MAX_STRING_SIZE * sizeof(char));
  if(mytree->root) {
    if(mytree->root->color)
      strcat(result, "(Red ");
    else
      strcat(result, "(Black ");
    strcat(result, valToString(mytree->root->value));
    strcat(result, " ");
    struct RBT *leftTree = malloc(sizeof(struct RBT));
    struct RBT *rightTree = malloc(sizeof(struct RBT));
    initRBT(leftTree);
    initRBT(rightTree);
    leftTree->root = mytree->root->leftchild;
    rightTree->root = mytree->root->rightchild;
    strcat(result, RBTtoString(leftTree, valToString));
    strcat(result, " ");
    strcat(result, RBTtoString(rightTree, valToString));
    strcat(result, ")");
    free(leftTree);
    free(rightTree);
    return result;
  }
  return "()";
}
