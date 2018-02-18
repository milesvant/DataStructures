#include <stdio.h>
#include <stdlib.h>
#include "mystack.h"

/*
 * Returns 1 if the stack is empty, and 0 otherwise
 */
int stackempty(struct Stack *myStack) {
  return (myStack->top == -1);
}

/*
 * Adds data to the top of myStack
 * Returns a pointer to the added data upon completion, or NULL upon failure
 */
void *push(struct Stack *myStack, void *data) {
  if(myStack->top >= myStack->max_size) { // Overflow
    return NULL;
  }
  (myStack->top)++;
  *(myStack->data + myStack->top) = data;
  return *(myStack->data + myStack->top);
}

/*
 * Return pointer to top element and remove the top element of
 * the stack upon completion, or NULL upon failure
 */
void *pop(struct Stack *myStack) {
  if(stackempty(myStack)) { // Underflow
    return NULL;
  }
  void *poppedData = *(myStack->data + myStack->top);
  (myStack->top)--;
  return poppedData;
}

/*
 * Remove all items and free all memory in myStack
 */
void clearstack(struct Stack *myStack) {
  free((myStack -> data));
  free(myStack);
}
