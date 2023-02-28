/**
 * @author Milind Singh
 * @date 02/14/2023
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define STRING_LEN 50u

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
    printf("Palindrome Permutation:\n"
           "Given a string, write a function to check if it is a permutation of a palindrome.\n"
           "A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters.\n"
           "The palindrome does not need to be limited to just dictionary words.\n");
}


/**
 * @brief Check if string is a palindrome permutation
 * @param str 
 */
static bool palindrome_permutation(const char* str)
{

}

int main(void)
{
    log_ques();

    char str[STRING_LEN];

    printf("Enter phrase:\n");
    fgets(str, STRING_LEN, stdin);

    printf("String = %s", str);

    return 0;
}