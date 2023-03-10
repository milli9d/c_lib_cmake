/**
 * @author Milind Singh
 * @date 3/12/2023
 *
 * @brief C Wrapper Library
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "common_defines.h"

/**
 * @brief Swap two integers in place
 * @param a
 * @param b
 */
void swap(int *a, int *b)
{
    /* sanity check */
    if (a == NULL || b == NULL) {
        return;
    }

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}