#include <stdio.h>
#include <stdint.h>

#include "include/hashmap.h"

int main(int argc, char **argv)
{

    hashmap_t test;
    init_hashmap(&test, &byte_checksum_extrapolate);

    for(int i = 0 ; i < 200u ; i++) {
        hashmap_insert(&test, i);
    }

    print_map(&test);

    hashmap_search(&test, 10u);
    hashmap_search(&test, 132u);

    printf("Finish\n");

    return 0;
}