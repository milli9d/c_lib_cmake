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
static void swap1(int *a, int *b);
static void swap2(int *a, int *b);

/* ================================================================ STATIC API */

/**
 * @brief Log out the question
 *
 */
static void log_ques(void)
{
    /* log question */
    printf("Number Swapper:\n"
           "Write a function to swap a number in place (that is, without temporary variables).\n");
}

/**
 * @brief Swap using XOR
 * @param a
 * @param b
 */
static void swap1(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/**
 * @brief Swap using ADD
 * @param a
 * @param b
 */
static void swap2(int *a, int *b)
{
    *a = *a + *b; // *a => 10 + 20 = 30
    *b = *a - *b; // *b => 30 - 20 = 10
    *a = *a - *b; // *a => 30 - 10 = 20
}

int main(void)
{
    log_ques();

    int a = 10u;
    int b = 20u;

    printf("a = %d, b = %d\n", a, b);
    swap1(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    swap2(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}