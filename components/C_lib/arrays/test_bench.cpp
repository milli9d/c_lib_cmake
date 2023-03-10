#include <stdio.h>
#include <stdint.h>

#include "array.h"
#include "2d_array.h"
#include "common_defines.h"

#define EL_SZ 1000u
#define R 5u
#define C 3u

int main(int argc, char **argv)
{
    int arr[EL_SZ];

    for (int i = 0; i < EL_SZ; i++) {
        arr[i] = i * 8;
    }

    print_arr(arr, EL_SZ);

    print_matrix_1d(R, R, arr);

    transpose_matrix_1dn(R, arr);
    print_matrix_1d(R, R, arr);

    for (int i = 0; i < EL_SZ; i++) {
        arr[i] = i * 16;
    }

    rotate_matrix(R, C, arr);
    print_matrix_1d(R, C, arr);
    spiral_print_matrix(R, C, arr);


    return 0;
}