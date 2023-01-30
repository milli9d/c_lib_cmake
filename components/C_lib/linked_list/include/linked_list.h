/**
 * @brief Linked List
 *
 * @author Milind Singh
 *
 * @date 2/1/2023
 */

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct node_s
{
    struct node_s *next;
    uint8_t val;
} node_t;

bool pop_node(node_t **head);
void push_node(node_t **head, uint8_t val);
void append_node(node_t **head, uint8_t val);
bool delete_node(node_t **head, uint32_t idx);
bool insert_node(node_t **head, uint32_t idx, uint8_t val);

bool reverse_i(node_t **head);
bool reverse_r(node_t **head);

node_t* search_val(node_t *head, uint8_t val);

bool empty_list(node_t **head);
void print_list_rf(const node_t *head);
void print_list_rb(const node_t *head);

void print_list(const node_t *head);

#endif /* _LINKED_LIST_H */