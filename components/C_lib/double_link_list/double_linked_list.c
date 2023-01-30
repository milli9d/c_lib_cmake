/**
 * @brief Doubly Linked Linked List
 *
 * @author Milind Singh
 *
 * @date 2/8/2023
 */

#include <stdio.h>

#include "include/double_linked_list.h"

/* ============================================================ Private API */

static dnode_t *new_node(uint8_t val);
// static dnode_t *reverse_sub_list(dnode_t *head);

/**
 * @brief Create a new doubly linked node
 */
static dnode_t *new_node(uint8_t val)
{
    /* create a new node */
    dnode_t *out = (dnode_t *)malloc(sizeof(dnode_t));

    /* null pointers */
    out->next = NULL;
    out->prev = NULL;

    /* attach value */
    out->val = val;

    return out;
}

/**
 * @brief Push a node to the front of the list
 */
void push_node(dlist_t *list, uint8_t val)
{
    /* sanity check */
    if (list == NULL) {
        printf("List is invalid.\n");
        return;
    }

    /* make a new node */
    dnode_t *node = new_node(val);

    /* if there was head then correct pointers */
    if (list->head != NULL) {
        node->next = list->head;
        (list->head)->prev = node;
    }

    /* attach the new node */
    if (list->head == NULL) {
        list->tail = node;
    }
    list->head = node;
}

/**
 * @brief Pop a node out from the tail end
 * 
 */
bool pop_node(dlist_t *list)
{
    

    return true;
}

/**
 * @brief Print list
 */
void print_list(const dlist_t *list, bool isFwd)
{
    /* sanity check */
    if (list == NULL) {
        printf("List is invalid.\n");
    }

    /* traverse and print list */
    const dnode_t *itr = NULL;
    if (isFwd) {
        itr = list->head;
        printf("HEAD --");
    } else {
        itr = list->tail;
        printf("TAIL --");
    }

    while (itr != NULL) {
        printf(" %d --", itr->val);
        if (isFwd) {
            itr = itr->next;
        } else {
            itr = itr->prev;
        }
    }

    printf("\n");
}
