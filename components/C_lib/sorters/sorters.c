/**
 * @brief Common Sorting Algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "include/sorters.h"

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/**
 * Bubble Sort | Runtime: 0(n2) average and worst case. Memory: 0( 1) .
 * In bubble sort, we start at the beginning of the array and swap the first two elements if the first is greater
 * than the second. Then, we go to the next pair, and so on, continuously making sweeps of the array until it is
 * sorted. In doing so, the smaller items slowly"bubble" up to the beginning of the list.
 */
void bubble_sort(int *arr, size_t sz)
{
    /* sanity checks */
    if (arr == NULL || sz == 0u)
    {
        return;
    }

    for (int i = 0; i < sz; i++)
    {
        int count_swap = 0;
        for (int j = 0; j < sz - 1u; j++)
        {
            /* swap if first is greater than next */
            int *curr = &arr[j];
            int *next = &arr[j + 1];

            if (*curr > *next)
            {
                swap(curr, next);
                count_swap++;
            }
        }
        if (count_swap == 0)
        {
            return;
        }
    }
}

/**
 * Selection Sort | Runtime: 0(n2) average and worst case. Memory: 0( 1).
 * Selection sort is the child's algorithm: simple, but inefficient.
 * Find the smallest element using a linear scan and move it to the front
 * (swapping it with the front element). Then, find the second smallest and move it,
 * again doing a linear scan. Continue doing this until all the elements are in place.
 */
void selection_sort(int *arr, size_t sz)
{
    /* sanity checks */
    if (arr == NULL || sz == 0u) { return; }

    /* sort */
    for (int i = 0; i < sz - 1; i++) {

        int *curr = &arr[i];
        int *min = &arr[i];

        /* find minimum element */
        for (int j = i + 1; j < sz; j++) {
            if (min == NULL || arr[j] < *min) {
                min = &arr[j];
            }
        }

        /* here we have the required min element and switch idx element */
        if (min != curr) {
            swap(min, curr);
        }
    }
}
