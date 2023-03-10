/**
 * @brief C Linked List container implementation
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/* ============================================================== Static API */

static node_t *new_node(uint32_t val);

/**
 * @brief Allocate a new node and fill with val
 */
static node_t *new_node(uint32_t val)
{
    node_t *out = (node_t *)malloc(sizeof(node_t));
    out->next = NULL;
    out->val = val;
    return out;
}

/* ============================================================== Public API */

/**
 * @brief Pretty print the linked list
 *
 * @param head  List to print
 */
void list_print(const node_t *head)
{
    printf("HEAD -> ");
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("TAIL\n");
}

/**
 * @brief Push to front of list
 *
 */
err_t list_push_front(node_t **head, uint32_t val)
{
    /* sanity checks */
    if (head == NULL) {
        return ERR_INVALID_POINTER;
    }

    /* allocate a new node */
    node_t *n_node = new_node(val);

    /* if there is already content in list, then attach to new node */
    if (*head != NULL) {
        n_node->next = *head;
    }
    *head = n_node;

    return ERR_OK;
}

/**
 * @brief Get size of a linked list
 *
 * O(n) time
 *
 * @param   head    Linked list to measure
 * @return          size of linked list
 */
size_t list_size(node_t *head)
{
    size_t count = 0u;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/**
 * @brief Insert a node into the linked list
 *
 * O(idx) time complexity.
 *
 * @param   head    linked list pointer
 * @param   idx     index to insert to
 * @param   val     value to insert
 *
 * @return err_t    error code
 */
err_t list_insert(node_t **head, size_t idx, uint32_t val)
{
    /* sanity checks */
    if (head == NULL) {
        printf("Error: Invalid List.\n");
        return ERR_INVALID_POINTER;
    }

    /* CASE-1: if idx is 0u */
    if (idx == 0u) {
        return list_push_front(head, val);
    }

    /* CASE-2: if index is within bounds */
    /* traverse to node before idx */
    node_t *itr = *head;
    while (itr != NULL && idx > 1u) {
        itr = itr->next;
        idx--;
    }

    /* if we overflowed then exit */
    if (itr == NULL || idx > 1u) {
        return ERR_OUT_OF_RANGE;
    }

    /* add node in between */
    node_t *n_node = new_node(val);

    /* if there was more list after this idx , attach that */
    if (itr->next != NULL) {
        n_node->next = itr->next;
    }

    /* attach node */
    itr->next = n_node;

    return ERR_OK;
}

/**
 * @brief Pop the head node from the linked list
 * 
 * @param   head    
 * 
 * @return  err_t    error code
*/
err_t list_pop_head(node_t **head)
{
    /* sanity check */
    if(head == NULL) {
        return ERR_INVALID_POINTER;
    }

    /* copy head for deletion */
    node_t *to_del = *head;

    /* change head to whatever's next */
    *head = (*head)->next;

    /* deallocate memory */
    free(to_del);
    to_del = NULL;

    return ERR_OK;
}

/**
 * @brief Delete idx element from linked list
 * 
 * @param head
 * @param idx
 * @return
 *
 */
err_t list_delete(node_t **head, size_t idx)
{
    /* sanity check */
    if(head == NULL || *head == NULL) {
        return ERR_INVALID_POINTER;
    }

    /* special case: delete head */
    if (idx == 0u) {
        return list_pop_head(head);
    }

    /* traverse to the node before idx to be deleted */
    node_t* itr  = *head;
    while (itr != NULL && idx > 1u) {
        itr = itr->next;
        idx--;
    }

    /* check if we overflowed or node doesn't exist */
    if(itr == NULL || itr->next == NULL) {
        printf("Error: Delete index oveflowed\n");
        return ERR_OUT_OF_RANGE;
    }

    /* collect pointers */
    node_t* to_del = itr->next;
    node_t* link_fw = to_del->next;

    /* connect rest of the list */
    itr->next = link_fw;

    /* deallocate node */
    free(to_del);
    to_del = NULL;

    return ERR_OK;
}

/**
 * @brief Iteratively reverse a linked list
 * @param       head        head of the list
 * @return      err_t       error code
 */
err_t list_reverse_i(node_t** head)
{
    /* sanity check */
    if (head == NULL || *head == NULL) {
        return ERR_INVALID_POINTER;
    }

    /* iterate and reverse links on each element pair */
    node_t *curr = *head;
    node_t *prev = NULL;

    while (curr != NULL) {
        /* store to traverse to next node */
        node_t *link_fw = curr->next;

        /* reverse links */
        curr->next = prev;

        /* traverse to next pair */
        prev = curr;
        curr = link_fw;
    }

    /* set head to last element seen */
    *head = prev;

    return ERR_OK;
}
