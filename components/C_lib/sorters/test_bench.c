/**
 * @brief Common Sorting Algorithms TB
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorters.h"

#define ARR_SIZE    25u

static void print_arr(int* arr, size_t sz)
{
    for(size_t i = 0u ; i < sz ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[ARR_SIZE] = {0u};

    srand((unsigned long int)&arr[0]);

    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 1000u;
    }

    print_arr(arr, ARR_SIZE);

    selection_sort(arr, ARR_SIZE);
    print_arr(arr, ARR_SIZE);

    return 0;
}