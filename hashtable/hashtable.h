#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#define NUM_BUCKETS 53
#include "../SinglyLinkedList/SinglyLinkedList.h"

struct KVPair {
  void *key;
  void *value;
};

struct HashTable {
  int (*hash)(const void *);
  struct SinglyLinkedList *buckets;
};

/*
 * Initializes table with the given hash function and NUM_BUCKETS buckets
 */
static inline void initHashTable(struct HashTable *table,
    int (*hash)(const void *)) {
  table->buckets = malloc(NUM_BUCKETS * sizeof(struct SinglyLinkedList));
  table->hash = hash;
  for(int i=0; i < NUM_BUCKETS; ++i) {
    initList(table->buckets + i);
  }
}

/*
 * Inserts a given key, value pair into mytable, then returns the resultant
 * KVPair. If the key already exists in mytable, then NULL is the return value.
 * Comparison function is needed to determine whether the key already exists in
 * mytable.
 */
void *chainedinsert(struct HashTable *mytable, void *key, void *value,
  int (*)(const void *, const void *));

/*
 * Searches for a given key in mytable using the given comparison function
 * (which returns 1 on match, 0 otherwise). Returns the value pointer if found,
 * otherwise returns NULL.
 */
void *chainedsearch(struct HashTable *mytable, void *key,
  int (*)(const void *, const void *));

/*
 * Searches for a given key in mytable and deletes it, then returns the value pointer
 * if found, and NULL otherwise. Comparison function returns 1 if the arguments
 * point to the same value, and 0 otherwise.
 */
void *chaineddelete(struct HashTable *mytable, void *key,
  int (*)(const void *, const void *));

/*
 * Deletes all entries and frees all memory in mytable.
 */
void deleteall(struct HashTable *mytable);

#endif
