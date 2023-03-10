/**
 * @brief Linked List
 *
 * @author Milind Singh
 *
 * @date 2/1/2023
 */

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

    typedef enum err_e
    {
        ERR_OK = 0,
        ERR_OUT_OF_RANGE = 1,
        ERR_INVALID_POINTER = 2,
        ERR_GENERIC = 99
    } err_t;

    typedef struct node_s
    {
        struct node_s *next;
        uint32_t val;
    } node_t;

    /* ================================================================== Miscellaneous */

    void list_print(const node_t *head);
    size_t list_size(node_t *head);
    void list_error_printer(int32_t error);

    /* ================================================================== List [Element] Manipulation */

    err_t list_push_front(node_t **head, uint32_t val);
    err_t list_insert(node_t **head, size_t idx, uint32_t val);
    err_t list_delete(node_t **head, size_t idx);

    /* ================================================================== List [Whole]  Manipulation */
    err_t list_reverse_i(node_t **head);

#ifdef __cplusplus
}
#endif /* extern 'C' */
#endif /* _LINKED_LIST_H */