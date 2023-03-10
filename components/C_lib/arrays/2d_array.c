/**
 * @author Milind Singh
 * @date 3/12/2023
 *
 * @brief C 2D Array Wrapper Library
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "2d_array.h"
#include "common_defines.h"

/**
 * @brief Get index of 2d array element in 1d array
 * @param   i   1st index of 2d element: arr[first][second]     
 * @param   j   2nd index of 2d element
 * @param   r   number of rows
 * @param   c   number of columns
 * @return 
 */
size_t get_idx(size_t i, size_t j, size_t r, size_t c)
{
    /* sanity checks */
    if (i >= r || j >= c) {
        printf("\nError: Out of bounds\n");
        return 0u;
    }

    size_t out = (i * c) + j;
    return out;
}

/**
 * @brief Pretty print a 2d_array
 * @param r     number of rows
 * @param c     number of columns
 * @param arr   1d array with 2d elements : row order
 */
void print_matrix_1d(int r, int c, int *arr)
{
    /* sanity checks */
    if(arr == NULL) {
        return;
    }

    /* iterate and print according to bounds given */
    for (int i = 0; i < r; i++) {
        printf("[ ");
        for (int j = 0; j < c; j++) {
            printf("%4d ", arr[get_idx(i, j, r, c)]);
        }
        printf("]\n");
    }
    printf("\n");
}

/**
 * @brief Transpose the given 2D array
 * @param n     number of rows and columns
 * @param arr   array
 */
void transpose_matrix_1dn(int n, int *arr)
{
    /* sanity check */
    if (arr == NULL) {
        return;
    }

    /* transpose means to make columns the rows and vice versa */
    for (size_t i = 0u; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            swap(&arr[get_idx(i, j, n, n)],
                 &arr[get_idx(j, i, n, n)]);
        }
    }
}

void spiral_print_matrix(int n, int m, int *arr)
{
    /* sanity check */
    if (arr == NULL) { return; }

    /* maintain four pointers starting at corners [relay-race/pass the baton] */
    int top = 0u;
    int bottom = n - 1;
    int left = 0u;
    int right = m - 1;

    while (1)
    {
        if (left > right) { break; }

        for (int i = left; i <= right; i++) {
            printf(" %d ", arr[get_idx(top, i, n, m)]);
        }
        top++;
        if (top > bottom) { break; }


        for (int i = top; i <= bottom; i++) {
            printf(" %d ", arr[get_idx(i, right, n, m)]);
        }
        right--;
        if (left > right) { break; }


        for (int i = right; i >= left; i--) {
            printf(" %d ", arr[get_idx(bottom, i, n, m)]);
        }
        bottom--;
        if (top > bottom) { break; }

        for (int i = bottom; i >= top; i--) {
            printf(" %d ", arr[get_idx(i, left, n, m)]);
        }
        left++;
    }
    printf("\n");
}

void rotate_matrix(int n, int m, int *arr)
{
}