#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "../SinglyLinkedList/SinglyLinkedList.h"

void *chainedinsert(struct HashTable *mytable, void *key, void *value,
    int (*compar)(const void *, const void *)) {
  if(chainedsearch(mytable, key, compar)) // If key already exists
    return NULL;
  int hashval = (*(mytable->hash))(key);
  struct KVPair *mypair = malloc(sizeof(struct KVPair));
  mypair->key = key;
  mypair->value = value;
  insertFront((mytable->buckets) + hashval, mypair);
  return (mytable->buckets + hashval)->head;
}

void *chainedsearch(struct HashTable *mytable, void *key,
    int (*compar)(const void *, const void *)) {
  // Find bucket
  int hashval = (*(mytable->hash))(key);
  struct SinglyLinkedList *bucket = (mytable->buckets + hashval);
  struct Node *start = bucket->head;
  // Search for key within bucket
  while(start) {
    struct KVPair *startPair = (struct KVPair *)(start->data);
    if(compar(startPair->key, key)) {
      return (startPair->value);
    }
    start = start->next;
  }
  return NULL;
}

void *chaineddelete(struct HashTable *mytable, void *key,
    int (*compar)(const void *, const void *)) {
  int hashval = (*(mytable->hash))(key);
  struct SinglyLinkedList *bucket = (mytable->buckets + hashval);
  struct Node *prevNode = NULL;
  struct Node *start = bucket->head;
  // Search for key within bucket
  while(start) {
    struct KVPair *startPair = (struct KVPair *)(start->data);
    if(compar(startPair->key, key)) { // On match, delete KVPair and return KVPair's value
      if(prevNode)
        prevNode->next = start->next;
      else
        bucket->head = NULL;
      void *returnval = startPair->value;
      free(startPair);
      free(start);
      return returnval;
    }
    prevNode = start;
    start = start->next;
  }
  return NULL;
}

void deleteall(struct HashTable *mytable) {
  struct SinglyLinkedList *bucket = mytable->buckets;
  for(int i=0; i < NUM_BUCKETS; ++i) {
    while(bucket[i].head) {
      free(popFront(bucket + i));
    }
  }
}
