#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked_list.h"

int main(int argc, char **argv)
{
    node_t *list = ll_prepend(1, ll_prepend(2, ll_prepend(3, NULL)));
    printf("len: %ld\n", ll_length(list));
    puts(ll_string(list));
    assert(ll_get(list, 1)->value == 2);
    printf("%d\n", ll_get(list, 0)->value);
}