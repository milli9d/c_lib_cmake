/**
 * @author Milind Singh
 * @date 3/12/2023
 *
 * @brief C 2D Array Wrapper Library
 *
 */

#ifndef _C_2D_ARRAY_H
#define _C_2D_ARRAY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

    size_t get_idx(size_t i, size_t j, size_t r, size_t c);

    void print_matrix_1d(int r, int c, int *arr);

    void transpose_matrix_1dn(int n, int *arr);

    void rotate_matrix(int n, int m, int *arr);
    
    void spiral_print_matrix(int n, int m, int *arr);


#ifdef __cplusplus
}
#endif

#endif /* _C_2D_ARRAY_H */