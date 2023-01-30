/**
 * @brief Linked List
 *
 * @author Milind Singh
 *
 * @date 2/1/2023
 */

#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct dnode_s {
    uint8_t val;
    struct dnode_s *next;
    struct dnode_s *prev;
} dnode_t;

typedef struct dlist_s {
    dnode_t *head;
    dnode_t *tail;
    size_t size;
} dlist_t;

bool pop_node(dlist_t *list);
void push_node(dlist_t *list, uint8_t val);
void append_node(dnode_t **head, uint8_t val);
bool delete_node(dnode_t **head, uint32_t idx);
bool insert_node(dnode_t **head, uint32_t idx, uint8_t val);

bool reverse_i(dnode_t **head);
bool reverse_r(dnode_t **head);

dnode_t* search_val(dnode_t *head, uint8_t val);

bool empty_list(dnode_t **head);
void print_list_rf(const dnode_t *head);
void print_list_rb(const dnode_t *head);

void print_list(const dlist_t *list, bool isFwd);

#endif /* _DOUBLE_LINKED_LIST_H */