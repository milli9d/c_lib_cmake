/**
 * @brief Hashmap
 *
 * @author Milind Singh
 *
 * @date 2/1/2023
 */

#ifndef _HASHMAP_H
#define _HASHMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "../../linked_list/include/linked_list.h"

#define HASH_TABLE_SZ           25u
#define HASH_TABLE_DATA_T       uint8_t
#define HASH_TABLE_DATA_SZ      sizeof(HASH_TABLE_DATA_T)

typedef size_t (*hash_func)(void *);

/**
 * @brief hashmap_t encapsulates a C style hashmap implementation
 * 
 * @param handler       Hashing function
 * @param hash_table    Hash table that stores linked lists
 */
typedef struct hashmap_s {
    hash_func handler;
    node_t *hash_table[HASH_TABLE_SZ];
} hashmap_t;

size_t byte_checksum_extrapolate(void *data);
void init_hashmap(hashmap_t *map, hash_func handler);
bool hashmap_insert(hashmap_t *map, HASH_TABLE_DATA_T val);
node_t *hashmap_search(hashmap_t *map, HASH_TABLE_DATA_T val);
void print_map(hashmap_t *map);

#endif /* _HASHMAP_H */