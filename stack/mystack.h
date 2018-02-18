#ifndef _MYSTACK_H_
#define _MYSTACK_H_

struct Stack {
  int max_size;
  int top;
  void **data;
};

/*
 * Initialize an empty stack that holds at most size elements.
 * Returns pointer to the stack or NULL upon failure
 */
static inline struct Stack *initstack(int size) {
  struct Stack *stackPointer = malloc(sizeof(struct Stack));
  if(stackPointer == NULL) {
    return NULL;
  }
  stackPointer->top = -1;
  stackPointer->data = malloc(sizeof(void *) * size);
  if(stackPointer->data == NULL){
    return NULL;
  }
  stackPointer->max_size = size;
  return stackPointer;
}

/*
 * Returns 1 if the stack is empty, and 0 otherwise
 */
int stackempty(struct Stack *myStack);

/*
 * Adds data to the top of myStack
 * Returns a pointer to the added data upon completion, or NULL upon failure
 */
void *push(struct Stack *myStack, void *data);

/*
 * Return and remove the top element of the stack upon completion, or NULL
 * upon failure
 */
void *pop(struct Stack *myStack);

/*
 * Remove all items and free all memory in myStack
 */
void clearstack(struct Stack *myStack);

#endif
