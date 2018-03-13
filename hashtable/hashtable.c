#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "../singlylinkedlist/singlylinkedlist.h"

int hash(const void *val) {
  int k = *(int *)val;
  return ((k * (k + 3)) % NUM_BUCKETS);
}

void *chainedinsert(struct HashTable *mytable, void *key, void *value) {
  int hashval = hash(key);
  if(((mytable->buckets) + hashval) == NULL) {
    initList(mytable->buckets + hashval);
  }
  struct KVPair mypair = { key, value };
  insertFront(mytable->buckets, &mypair);
  return (mytable->buckets + hashval)->head;
}

void *chainedsearch(struct HashTable *mytable, void *key,
    int (*compar)(const void *, const void *)) {
  int hashval = hash(key);
  if(mytable->buckets + hashval == NULL) {
    return NULL;
  }

  struct singlylinkedlist *bucket = (mytable->buckets + hashval);
  struct Node *start = bucket->head;
  while(start) {
    if(compar(start->data, key)) {
      return start;
    }
    start = start->next;
  }
  return NULL;
}

void *chaineddelete(struct HashTable *mytable, void *key,
    int (*compar)(const void *, const void *)) {
  int hashval = hash(key);
  if((mytable->buckets + hashval) == NULL) {
    return NULL;
  }
  struct singlylinkedlist *bucket = (mytable->buckets + hashval);
  while(bucket->head) {
    if(((struct KVPair *)(bucket->head->data))->key == key) {
      struct KVPair *kvpointer = (struct KVPair *)(bucket->head->data);
      // HAVE TO DELETE HERE
      return kvpointer;
    }
    bucket->head++;
  }
  return NULL;
}
