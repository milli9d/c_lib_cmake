/**
 * @brief Linked List
 *
 * @author Milind Singh
 *
 * @date 2/1/2023
 */

#include <stdio.h>

#include "include/linked_list.h"

/* ============================================================ Private API */

static node_t *new_node(uint8_t val);
static node_t *reverse_sub_list(node_t *head);

/**
 * @brief Make a new node with value val
 */
static node_t *new_node(uint8_t val)
{
    node_t *out = (node_t *)malloc(sizeof(node_t));
    out->next = NULL;
    out->val = val;
    return out;
}

/**
 * @brief Recursion for reversing a linked list
*/
static node_t *reverse_sub_list(node_t *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node_t *rest = reverse_sub_list(head->next);

    head->next->next = head;
    head->next = NULL;

    return rest;
}

/* ============================================================ Public API */

/**
 * @brief Push a node to the front of the linked list
 */
void push_node(node_t **head, uint8_t val)
{
    /* sanity check */
    if (head == NULL) {
        printf("ERROR: List is invalid.\n");
        return;
    }

    /* make new node */
    node_t *out = new_node(val);

    /* check if list is empty */
    if (*head == NULL) {
        /* make this new node the head of the list */
        *head = out;
    } else {
        /* attach current head to new node and replace head */
        out->next = *head;
        *head = out;
    }
}

/**
 * @brief Append a new node to the end of a linked list
 */
void append_node(node_t **head, uint8_t val)
{
    /* sanity check */
    if (head == NULL) {
        printf("ERROR: List is invalid.\n");
        return;
    }

    /* make new node */
    node_t *n_node = new_node(val);

    /* check if list is empty */
    if (*head == NULL) {
        /* make new node the head of the list */
        *head = n_node;
    } else {
        /* traverse to the last element of the list */
        node_t *itr = *head;
        while (itr != NULL && itr->next != NULL) {
            itr = itr->next;
        }
        /* attach node to the last element */
        itr->next = n_node;
    }
}

/**
 * @brief Pop a node from the front of list
 */
bool pop_node(node_t **head)
{
    /* gather pointers for delete */
    node_t *to_delete = *head;

    /* detach node */
    *head = (*head)->next;

    /* free node */
    free(to_delete);
    to_delete = NULL;

    return true; 
}

/**
 * @brief Delete a node at idx
 */
bool delete_node(node_t **head, uint32_t idx)
{
    /* sanity check */
    if (head == NULL || *head == NULL) {
        printf("ERROR: List is invalid.\n");
        return false;
    }

    /* special case; delete HEAD */
    if (idx == 0u) {
        return pop_node(head);
    }

    /* if list is not empty then find and delete idx */
    node_t* itr = *head;

    /* traverse to the node before idx */
    while (itr != NULL && idx > 1u) {
        itr = itr->next;
        idx--;
    }

    /* check that the element to be deleted exists */
    if (itr == NULL || itr->next == NULL) {
        printf("ERROR: Invalid idx.\n");
        return false;
    }

    /* now we have itr pointing to element before element to be deleted */
    /* gather pointers for delete */
    node_t* to_delete = itr->next;
    node_t* link_next = to_delete->next;

    /* detach node */
    itr->next = link_next;

    /* free node */
    free(to_delete);
    to_delete = NULL;

    return true;
}

/**
 * @brief Insert node at given index , 
 * 
 * @return true     if node insert failed 
 * @return false    if node inserted
 */
bool insert_node(node_t** head, uint32_t idx, uint8_t val)
{
    /* sanity check */
    if (head == NULL) {
        printf("ERROR: List is invalid.\n");
        return false;
    }

    /* if append at head */
    if (idx == 0) {
        push_node(head, val);
        return true;
    }

    /* traverse to element befor idx element */
    node_t *itr = *head;
    while (itr != NULL && (idx--) > 1u) {
        itr = itr->next;
    }

    /* check for overflow */
    if (itr == NULL) {
        printf("ERROR: Insert index out of bounds.\n");
    }

    /* gather pointers */
    node_t *link_next = itr->next;

    /* insert the new node */
    node_t *n_node = new_node(val);
    n_node->next = link_next;
    itr->next = n_node;

    return true;
}

/**
 * @brief Reverse a Linked List recursively
*/
bool reverse_r(node_t **head)
{
    if (head == NULL) {
        printf("ERROR: List is invalid.\n");
        return false;
    }
    *head = reverse_sub_list(*head);
    return true;
}

/**
 * @brief Reverse the linked list iteratively 
 */
bool reverse_i(node_t** head)
{
    /* sanity check */
    if (head == NULL || *head == NULL) {
        printf("ERROR: List is invalid.\n");
        return false;
    }

    /* if there's only one element */
    if ((*head)->next == NULL) {
        printf("WARN: List is only one element.\n");
        return true;
    }

    /* reverse the list */
    node_t* first = NULL;
    node_t* second = *head;

    /* traverse till the last element and reverse all pointers */
    while (second != NULL) {
        /* save next node for traversal */
        node_t* link_next = second->next;

        /* reverse link */
        second->next = first;

        /* traverse */
        first = second;
        second = link_next;
    }

    *head = first;

    return true;
}

/**
 * @brief Search for the given value in the list
*/
node_t* search_val(node_t *head, uint8_t val)
{
    node_t* out = NULL;
    
    if(head == NULL) {
        printf("Error: {search} List is empty.\n");
        return head;
    }

    /* traverse and find node */
    out = head;
    while(out != NULL && out->next != NULL) {
        if(out->val == val) {
            return out;
        }
        out = out->next;
    }

    return NULL;
}

/**
 * @brief Pretty print list recursively reverse direction
*/
void print_list_rb(const node_t *head)
{
    /* terminating condition */
    if (head == NULL) {
        printf("ERROR: {print} List is empty.\n");
        return;
    }
    print_list_rb(head->next);
    printf("[%d] -- ", head->val);
}

/**
 * @brief Pretty print list recursively forward direction
*/
void print_list_rf(const node_t *head)
{
    /* terminating condition */
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("[%d] -- ", head->val);
    print_list_rf(head->next);
}

/**
 * @brief Empty list recursively forward direction
*/
static node_t *empty_list_r(node_t *head)
{
    /* terminating condition */
    if (head == NULL) {
        printf("\n");
        return head;
    }
    
    /* gather pointers */
    node_t *link_forward = head->next;
    node_t *to_delete = head;
    
    /* pop node */
    free(to_delete);
    to_delete = NULL;
    
    /* return rest of the list */
    return empty_list_r(link_forward);
}

/**
 * @brief Empty list recursively forward direction
*/
bool empty_list(node_t** head)
{
    /* sanity check */
    if (head == NULL) {
        printf("ERROR: {empty_list} List is empty.\n");
        return false;
    }
    /* start recursion */
    *head = empty_list_r(*head);
    return true;
}

/**
 * @brief Fill a linked list with values upto TOP with increments of incr
 * @param head 
 * @param top 
 * @param incr 
 * @return 
 */
bool fill_list_r(node_t **head, int16_t top, int16_t incr)
{
    /* sanity check */
    if (head == NULL || incr <= 0 || top <= 0) {
        return false;
    }

    /* terminator */
    if (top <= 0u) {
        return true;
    }

    /* perform recursive action unit */
    push_node(head, (uint8_t)top);

    /* recurse */
    return fill_list_r(head, top - incr, incr);
}


/**
 * @brief Pretty print a linked list
 */
void print_list(const node_t *head)
{
    /* sanity check */
    if (head == NULL) {
        printf("ERROR: {print} List is empty.\n");
        return;
    }

    /* iterate over list and print nodes */
    const node_t *itr = head;
    uint32_t idx = 0u;
    printf("HEAD -->");
    while (itr != NULL) {
        printf(" [%d : %d] -->", idx++, itr->val);
        itr = itr->next;
    }
    printf(" TAIL\n");
}