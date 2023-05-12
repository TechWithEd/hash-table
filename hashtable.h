#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define __UNOCCUPIED_NODE__ 0x01
#define __OCCUPIED_NODE__   0x02
#define __DELETED_NODE__    0x04

typedef struct pair
{
    int status;
    struct pair *next;
    char *key;
    int val;
} pair_t;

typedef struct hashtable
{
    pair_t *data;
    size_t size;
    size_t capacity;
} *hashtable_t;

hashtable_t hashtable_new(size_t size);
void hashtable_insert(hashtable_t hashtable, char *key, int val);
void hashtable_remove(hashtable_t hashtable, char *key);
const int *hashtable_get(hashtable_t hashtable, char *key);
void hashtable_print(hashtable_t hashtable);
void hashtable_free(hashtable_t hashtable);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // __HASHTABLE_H__