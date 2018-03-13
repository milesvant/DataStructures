#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#define NUM_BUCKETS 53
#include "../singlylinkedlist/singlylinkedlist.h"

struct KVPair {
  void *key;
  void *value;
};

struct HashTable {
  struct singlylinkedlist *buckets;
};

static inline void initHashTable(struct HashTable *table) {
  table = malloc(sizeof(struct HashTable));
  table->buckets = malloc(NUM_BUCKETS * sizeof(struct singlylinkedlist));
}

void *chainedinsert(struct HashTable *mytable, void *key, void *value);

void *chainedsearch(struct HashTable *mytable, void *key,
  int (*)(const void *, const void *));

void *chaineddelete(struct HashTable *mytable, void *key,
  int (*)(const void *, const void *));

#endif
