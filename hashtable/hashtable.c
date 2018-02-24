#include <stdio.h>
#include <stdlib.h>
#include "hastable.h"
#include "singlylinkedlist.h"

void *chainedinsert(struct *HashTable mytable, void *key, void *value) {
  int hashval = mytable->hash(key);
  if((mytable->buckets + hashval)) == NULL) {
    initList(mytable->buckets + hashval);
  }
  struct KVPair mypair = { key, value };
  return (mytable->buckets + hashval)->head;
}

void *chainedsearch(struct *HashTable mytable, void *key) {
  int hashval = mytable->hash(key);
  if(mytable->buckets + hashval == NULL) {
    return NULL;
  }
  struct Singlylinkedlist bucket = *(mytable->buckets + hashval);
  while(bucket->head) {
    if(*(KVPair *)(bucket.head).key == key) {
      return *(KVPair *)(bucket.head).value;
    }
    bucket->head++;
  }
  return NULL;
}

void *chaineddelete(struct *HashTable mytable, void *key) {
  int hashval = mytable->hash(key);
  if((mytable->buckets + hashval) == NULL) {
    return NULL;
  }
  struct Singlylinkedlist bucket = *(mytable->buckets + hashval);
  while(bucket->head) {
    if(*(KVPair *)(bucket.head).key == key) {
      struct KVPair *kvpointer = *(KVPair *)(bucket.head)
      deleteNode(bucket, *kvpointer);
      return kvpointer;
    }
    bucket->head++;
  }
  return NULL;
}
