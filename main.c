#include "hashtable.h"
#include <stdint.h>
#include <stdio.h>

size_t hash(char *str)
{
    size_t res = 5381;
    char *s = str;
    while (*s != '\0')
    {
        res = (res << 5) + res + *s;
        ++s;
    }
    return res;
}

int main(void)
{
    hashtable_t hashtable = hashtable_new(10, hash);
    hashtable_insert(hashtable, "john", 32);
    hashtable_insert(hashtable, "johnny", 21);
    hashtable_insert(hashtable, "jennie", 24);
    hashtable_print(hashtable);
    hashtable_free(hashtable);
}
