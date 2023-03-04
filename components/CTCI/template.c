/**
 * @author Milind Singh
 * @date 02/14/2023
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

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
           "FOLLOW UP\n"
           "How would you solve this problem if a temporary buffer is not allowed?\n");
}

int main()
{
    log_ques();

    return 0;
}