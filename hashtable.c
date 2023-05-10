#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

static size_t hash(char *key, size_t size)
{
    size_t res = 0;
    for (int i = 0; key[i] != 0; i++)
    {
        res += key[i];
        res *= (res * key[i]);
    }
    return res % size;
}

hashtable_t hashtable_new(size_t size)
{
    hashtable_t buf = malloc(sizeof(struct hashtable));
    if (buf == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    buf->data = calloc(size, sizeof(pair_t));
    buf->capacity = size;
    buf->size = 0;
    return buf;
}

void hashtable_insert(hashtable_t hashtable, char *key, int val)
{
    pair_t pair = { __OCCUPIED_NODE__, NULL, key, val };
    int index = hash(key, hashtable->capacity);
    pair_t *node = &hashtable->data[index];
    while (node->next != NULL)
    {
        node = node->next;
        if (strcmp(node->key, key) == 0)
        {
            node->val = val;
            return;
        }
    }
    node->next = malloc(sizeof(pair_t));
    if (node->next == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    memcpy(node->next, &pair, sizeof(pair_t));
    hashtable->size++;
}

void hashtable_remove(hashtable_t hashtable, char *key)
{
    int index = hash(key, hashtable->capacity);
    pair_t *node = &hashtable->data[index];
    while (node->next != NULL)
    {
        node = node->next;
        if (strcmp(node->key, key) == 0)
        {
            node->status = __UNOCCUPIED_NODE__;
        }
    }
}

const int *hashtable_get(hashtable_t hashtable, char *key)
{
    int index = hash(key, hashtable->capacity);
    pair_t *node = &hashtable->data[index];
    while (node->next != NULL)
    {
        node = node->next;
        if (node->status == __OCCUPIED_NODE__)
        {
            if (strcmp(node->key, key) == 0)
            {
                return &node->val;
            }
        }
    }
    return NULL;
}

void hashtable_free(hashtable_t hashtable)
{
    for (int i = 0; i < hashtable->capacity; i++)
    {
        if (hashtable->data[i].next != NULL)
        {
            pair_t *node = hashtable->data[i].next;
            pair_t *prev = NULL;
            while (node != NULL)
            {
                prev = node;
                node = node->next;
                free(prev);
            }
        }
    }
    free(hashtable->data);
    free(hashtable);
}