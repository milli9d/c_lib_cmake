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
static void url_ify(char *str);
static size_t get_urlified_len(const char *str);

/* ================================================================ STATIC API */

/**
 * @brief Log out the question
 *
 */
static void log_ques(void)
{
    /* log question */
    printf("URLify:\n"
           "Write a method to replace all spaces in a string with '%20'.\n"
           "You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the 'true' length of the string.\n");
}

/**
 * @brief 
 */
static size_t get_urlified_len(const char *str)
{
    if (str == NULL) { return 0u; }

    size_t s1_len = strlen(str);
    size_t count = 0u;

    for (int i = 0; i < s1_len; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }

    return (s1_len + (count * 2));
}

/**
 * @brief URL-ify
 */
static void url_ify(char *str)
{
    if (str == NULL) {return "";}

    size_t len = strlen(str);
    size_t ext_len = get_urlified_len(str) - 1u;

    for (int i = len - 1u; i >= 0; i--)
    {
        if(str[i] == ' ') {
            /* put %20 at ext_len , decrement by 3 */
            str[ext_len--] = '0';
            str[ext_len--] = '2';
            str[ext_len--] = '%';
        } else {
            /* put char at ext_len */
            str[ext_len--] = str[i];
        }
    }
}

int main(void)
{
    log_ques();

    /* arrange test data */
    char str[STRING_LEN];

    printf("Enter First String:\n");
    fgets(str, STRING_LEN, stdin);

    printf("Str: %s\n", str);

    /* call check permutation */
    url_ify(str);
    printf("Output: %s\n", str);

    return 0;
}