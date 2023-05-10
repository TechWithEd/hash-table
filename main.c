#include "hashtable.h"
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    hashtable_t table = hashtable_new(10);
    hashtable_insert(table, "john", 27);
    hashtable_insert(table, "steve", 43);
    hashtable_insert(table, "michael", 18);

    printf("%d\n", *hashtable_get(table, "john"));
    printf("%d\n", *hashtable_get(table, "steve"));
    printf("%d\n", *hashtable_get(table, "michael"));
    hashtable_free(table);
    return 0;
}
