#include "hashtable.h"
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    hashtable_t hashtable = hashtable_new(16, NULL);
    hashtable_insert(hashtable, "richard", 32);
    hashtable_insert(hashtable, "johnny", 21);
    hashtable_insert(hashtable, "thomas", 24);
    hashtable_print(hashtable);
    hashtable_free(hashtable);
}
