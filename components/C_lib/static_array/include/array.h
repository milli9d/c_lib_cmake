/**
 * @author Milind Singh
 * @date 1/29/2023
 *
 * @brief C Array Wrapper Library
 *
 */

#ifndef _C_ARRAY_H
#define _C_ARRAY_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct array_s
{
    uint8_t *data;
    size_t size;
    size_t capacity;
    size_t data_len;
    bool is_inited;
} array_t;

bool array_wrap_empty(array_t *array, void *data,
                      size_t data_len, size_t array_len);

bool array_wrap(array_t *array, void *data,
                size_t data_len, size_t array_len,
                size_t array_size);

void *array_get(const array_t *array, size_t idx);

bool array_set(array_t *array, size_t idx, void *data);

void array_fill_random(array_t *arr, size_t arr_len);

#endif /* _C_ARRAY_H */