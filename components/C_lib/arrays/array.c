/**
 * @author Milind Singh
 * @date 3/12/2023
 *
 *
 * @brief C Array Wrapper Library
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "array.h"

/**
 * @brief Pretty print a static array
 * @param   arr   pointer to the array
 * @param   sz    size
 */
void print_arr(int *arr, size_t sz)
{
    printf("START\n");
    for (int i = 0; i < sz; i++) {
        printf("[%d] => %d\n", i, arr[i]);
    }
    printf("END\n");
}