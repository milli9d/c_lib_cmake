/**
 * @author Milind Singh
 * @date 02/27/2023
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

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
    printf("Word Frequencies:\n"
           "Design a method to find the frequency of occurrences of any given word in a book.\n"
           "What if we were running this algorithm multiple times?\n");
}

int main(void)
{
    log_ques();

    return 0;
}