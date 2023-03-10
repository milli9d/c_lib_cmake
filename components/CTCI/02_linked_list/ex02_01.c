/**
 * @author Milind Singh
 * @date 02/28/2023
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "linked_list.h"

/* ================================================================ STATIC API Declarations */

static void log_ques(void);

/* ================================================================ STATIC API */

/**
 * @brief Log out the question
 *
 */
static void log_ques(void)
{
    /* log question */
    printf("2.1 Remove Dups!\n"
           "Write code to remove duplicates from an unsorted linked list.\n"
           "FOLLOW UP : How would you solve this problem if a temporary buffer is not allowed?\n");
}

/* ================================================================ Linked List */

void delete_node_ptr(node_t** head, node_t* node) 
{
    /* search for the node in the list */
    node_t* itr = *head;
    while(itr != NULL && itr->next != node && itr->next != NULL) {
        itr=itr->next;
    }
    
    if (itr == NULL) {return;}

    node_t* to_del = itr->next;
    
    if (to_del->next != NULL) {
        itr->next = to_del->next;
    }

    free(to_del);
    to_del = NULL;
}


void remove_dups(node_t **head)
{
    /* sanity checks */
    if (head == NULL || *head == NULL) { return; }

    /* take two iterators, make one iterate over list and other find duplicates and remove them */
    node_t* itr1 = *head;
    node_t* itr2 = *head;
    
    while (itr1 != NULL && itr2 != NULL) {

        while(itr2 != NULL && itr2->next != NULL) {
            if (itr1->val == itr2->next->val)
            {
                delete_node_ptr(head, itr2);
            }

            itr2 = itr2->next;
        }
        
        itr1 = itr1->next;
    }

}

int main()
{
    log_ques();

    node_t* myList = NULL;

    list_push_front(&myList, 1u);
    list_push_front(&myList, 2u);
    list_push_front(&myList, 1u);
    list_push_front(&myList, 4u);
    list_push_front(&myList, 2u);
    list_push_front(&myList, 3u);

    remove_dups(&myList);

    list_print(myList);

    return 0;
}