#include "hashtable.h"
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    hashtable_t table = hashtable_new(10);
    hashtable_insert(table, "hyunjin", 100);
    hashtable_insert(table, "felix", 95);
    hashtable_insert(table, "lee know", 75);

    printf("%d\n", *hashtable_get(table, "hyunjin"));
    printf("%d\n", *hashtable_get(table, "felix"));
    printf("%d\n", *hashtable_get(table, "lee know"));
    hashtable_free(table);
    return 0;
}
