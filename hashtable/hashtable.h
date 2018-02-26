#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#define NUM_BUCKETS 53
#include "../singlylinkedlist/singlylinkedlist.h"

struct KVPair {
  void *key;
  void *value;
};

struct HashTable {
  int (hash)(void *);
  struct singlylinkedlist *buckets;
};

static inline void initHashTable(struct HashTable *table, int (*hash)(void *)) {
  table->buckets = malloc(NUM_BUCKETS * sizeof(struct singlylinkedlist));
  table->hash = *hash;
}

void *chainedinsert(struct HashTable *mytable, void *key, void *value);

void *chainedsearch(struct HashTable *mytable, void *key);

void *chaineddelete(struct HashTable *mytable, void *key);

#endif
