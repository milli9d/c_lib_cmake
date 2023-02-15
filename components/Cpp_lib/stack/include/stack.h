/**
 * @author Milind Singh
 * @date 2/3/2023
 *
 * @brief C Stack Library
 *
 */


#ifndef _C_ARRAY_H
#define _C_ARRAY_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include  "../../linked_list/include/linked_list.h"

/**
 * @brief 
 * 
 */
typedef struct stack_s {
    node_t* top;
    size_t size;
} stack_t;

bool stack_pop(stack_t* stack);
bool stack_reverse(stack_t* stack);
bool stack_is_empty(stack_t* stack);
bool stack_push(stack_t *stack, uint8_t val);
node_t* stack_peek(stack_t *stack);

#endif /* _C_ARRAY_H */