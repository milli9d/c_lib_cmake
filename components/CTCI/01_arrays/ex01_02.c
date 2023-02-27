/**
 * @author Milind Singh
 * @date 02/14/2023
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define STRING_LEN 20u

/* ================================================================ STATIC API Declarations */

static void log_ques(void);
static void printTrackArr(int16_t *arr, size_t sz);
static bool check_permutation(const char *str1, const char *str2);

/* ================================================================ STATIC API */

/**
 * @brief
 *
 */
static void log_ques(void)
{
    /* log question */
    printf("Check Permutation:\n"
           "Given two strings, write a method to decide if one is a permutation of the other.\n");
}

/**
 * @brief
 *
 * @param str1
 * @param str2
 */
static bool check_permutation(const char *str1, const char *str2)
{
    /* sanity check */
    if(str1 == NULL || str2 == NULL) { return false; }
    
    /* get lengths */
    size_t s1_len = strlen(str1);
    size_t s2_len = strlen(str2);
    if (s1_len != s2_len) { return false; }

    int16_t track[256u] = {0u};
    
    /* iterate through the str1 */
    for (size_t i = 0; i < s1_len; i++) {
        track[(size_t)str1[i]]++;
    }

    /* iterate through the str2 */
    for (size_t i = 0; i < s2_len; i++) {
        track[(size_t)str2[i]]--;
        if (track[(size_t)str2[i]] < 0) {
            return false;
        }
    }

    return true;
}

/**
 * @brief 
 * 
 * @param arr 
 * @param sz 
 */
static void printTrackArr(int16_t *arr, size_t sz)
{
    for (size_t i = 0u; i < sz; i++) {
        printf("ARR[%ld] %c: %d\n", i, (char)i, arr[i]);
    }
}

int main(void)
{
    log_ques();

    /* arrange test data */
    char str1[STRING_LEN];
    char str2[STRING_LEN];

    printf("Enter First String:\n");
    scanf("%s", str1);

    printf("Enter Second String:\n");
    scanf("%s", str2);

    printf("S1: %s S2: %s\n", str1, str2);

    /* call check permutation */
    printf("%s", (check_permutation(&str1[0u], &str2[0u]) == true ? "TRUE\n" : "FALSE\n"));

    return 0;
}