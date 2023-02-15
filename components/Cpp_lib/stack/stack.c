/**
 * @author Milind Singh
 * @date 2/3/2023
 *
 * @brief C Stack Library
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include  "../../linked_list/include/linked_list.h"
#include "include/stack.h"

/**
 * @brief Push value to stack LIFO
 * 
 * Push to head of linked list
 *
 * @param stack
 * @param val
 * @return true
 * @return false
 */
bool stack_push(stack_t *stack, uint8_t val)
{
    /* sanity check */
    if (stack == NULL) {
        printf("ERROR: Invalid stack pointer.\n");
        return false;
    }

    /* check if stack is empty */
    if (stack->top == NULL) {
        stack->size = 0u;
    }

    /* push node */
    push_node(&stack->top, val);
    stack->size++;

    return true;
}

/**
 * @brief Get pointer to the top element.
 * 
 * Do not pop the element
 * 
 * @param stack 
 * @return node_t* 
 */
node_t *stack_peek(stack_t *stack)
{
    /* sanity check */
    if (stack == NULL) {
        printf("ERROR: Invalid stack pointer.\n");
        return NULL;
    }

    return stack->top;
}

/**
 * @brief Pop the top element
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool stack_pop(stack_t *stack)
{
    /* sanity check */
    if (stack == NULL) {
        printf("ERROR: Invalid stack pointer.\n");
        return false;
    }
    return pop_node(&stack->top);
}


/**
 * @brief Return if stack empty
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool stack_is_empty(stack_t *stack)
{
    return ((stack == NULL) || (stack->top == NULL));
}

/**
 * @brief Reverse the stack by pushing all elements to new stack
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool stack_reverse(stack_t *stack)
{
    /* sanity check */
    if (stack == NULL) {
        printf("ERROR: Invalid stack pointer.\n");
        return false;
    }

    /* make a temp list */
    stack_t temp = {0u};

    /* pop and push all nodes to new list */
    while (!stack_is_empty(stack)) {
        node_t *to_move = stack_peek(stack);
        stack_push(&temp, to_move->val);
        stack_pop(stack);
        to_move = NULL;
    }

    /* set the head to the new list */
    stack->top = temp.top;
    return true;
}