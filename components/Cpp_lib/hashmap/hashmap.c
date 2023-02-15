/**
 * @brief Hashmap
 *
 * @author Milind Singh
 *
 * @date 2/1/2023
 */

#include <stdio.h>
#include <string.h>

#include "include/hashmap.h"

/* ============================================================ Private API */

static uint64_t checksum(void *dat, size_t num_bytes);

static uint64_t checksum(void *data, size_t num_bytes)
{
    uint64_t out = 0u;

    for (int i = 0; i < num_bytes; i++) {
        out += ((uint64_t)((uint8_t *)data)[i]) *
               ((uint8_t *)data)[i];
    }

    return out;
}

/* ============================================================= Public API */

/**
 * @brief
 *
 * @param data
 * @return int
 */
size_t byte_checksum_extrapolate(void *data)
{
    return checksum(data, (size_t)HASH_TABLE_DATA_SZ) %
           HASH_TABLE_SZ;
}

/**
 * @brief
 *
 * @param handler
 */
void init_hashmap(hashmap_t *map, hash_func handler)
{
    /* sanity check */
    if (map == NULL) {
        printf("Hashmap pointer invalid.\n");
        return;
    }

    /* clear out hash_table*/
    memset(&(map->hash_table[0u]), 0u, sizeof(node_t*) * HASH_TABLE_SZ);
    map->handler = handler;
}

/**
 * @brief Search the given map for a value
 * 
 * @param map 
 * @param val 
 */
node_t* hashmap_search(hashmap_t *map, HASH_TABLE_DATA_T val)
{
    /* sanity check */
    if (map == NULL) {
        printf("Hashmap pointer invalid.\n");
        return NULL;
    }

    /* perform hash function */
    size_t idx = map->handler(&val);

    /* search hash index linked list for value */
    node_t *out = search_val((map->hash_table[idx]), val);

    /* log value */
    if (out) {
        printf("Value %d found.\n", out->val);
    } else {
        printf("Value %d not found.\n", val);
    }
    
    return out;
}


/**
 * @brief 
 * 
 * @param map 
 * @param val 
 * @return true 
 * @return false 
 */
bool hashmap_insert(hashmap_t *map, HASH_TABLE_DATA_T val)
{
    /* sanity check */
    if (map == NULL) {
        printf("Hashmap pointer invalid.\n");
        return false;
    }

    /* perform hash function */
    size_t idx = map->handler(&val);

    /* push node to the hash index */
    push_node(&(map->hash_table[idx]), val);

    return true;
}

/**
 * @brief 
 * 
 * @param map 
 */
void print_map(hashmap_t* map)
{
    /* sanity check */
    if (map == NULL) {
        printf("Hashmap pointer invalid.\n");
        return;
    }

    /* go to each hash index and print each linked list */
    for (int i = 0; i < HASH_TABLE_SZ; i++) {
        printf("IDX[%2d]  ===  ", i);
        if (map->hash_table[i] != NULL) {
            print_list(map->hash_table[i]);
        } else {
            printf("Empty index.\n");
        }
    }
}