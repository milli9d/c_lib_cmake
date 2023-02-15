#include <stdio.h>
#include <stdint.h>

#include "include/array.h"

#define ARR_DATA_T uint16_t
#define ARR_LEN 25u

int main(int argc, char **argv)
{
    ARR_DATA_T test_arr[ARR_LEN] = {0u};
    array_t s_arr = {0u};

    array_wrap(&s_arr, &test_arr[0], sizeof(ARR_DATA_T), ARR_LEN, ARR_LEN);

    ARR_DATA_T test_val = {0u};
    array_set(&s_arr, 10u, &test_val);

    ARR_DATA_T *ptr = (ARR_DATA_T *)array_get(&s_arr, 10u);

    printf("%d\n", *ptr);

    return 0;
}