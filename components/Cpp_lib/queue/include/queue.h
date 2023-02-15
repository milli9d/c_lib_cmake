/**
 * @author Milind Singh
 * @date 2/3/2023
 *
 * @brief C Queue Library
 *
 */


#ifndef _C_QUEUE_H
#define _C_QUEUE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include  "../../linked_list/include/linked_list.h"

/**
 * The queue is a LIFO data-structure
 * 
 * Data is pushed from HEAD end 
 * and pulled from TAIL end.
 * 
 * We maintain both HEAD and TAIL pointers to keep track of the queue
 * 
 */
typedef struct queue_s {
    node_t* head;
    node_t* tail;
    size_t size;
} queue_t;





#endif /* _C_QUEUE_H */