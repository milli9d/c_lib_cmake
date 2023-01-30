/**
 * @author Milind Singh
 * @date 1/29/2023
 *
 * @brief C Array Wrapper Library
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "array.h"

/* ============================================================== PRIVATE DATA */

/* ============================================================== STATICS DECs */

/* ============================================================== PRIVATE API */

/* ============================================================== PUBLIC API */

/**
 * @brief Initialize an array
 */
bool array_wrap_empty(array_t *array, void *data,
                size_t data_len, size_t array_len)
{
    bool out = false;

    /* sanity checks */
    if (array == NULL || data == NULL ||
        data_len == 0u || array_len == 0u)
    {
        return out;
    }

    array->capacity = array_len;
    array->data = (uint8_t*)data;
    array->size = 0u;
    array->data_len = data_len;
    array->is_inited = true;

    return out;
}

/**
 * @brief Initialize an array with filled elements
 */
bool array_wrap(array_t *array, void *data,
                size_t data_len, size_t array_len,
                size_t array_size)
{
    bool ret = false;

    if (array_size <= array_len) {
        ret = array_wrap_empty(array, data, data_len, array_len);
        array->size = array_size;
    }

    return ret;
}

/**
 * @brief Get data at idx position
 */
void *array_get(const array_t *array, size_t idx)
{
    uint8_t *out = NULL;

    if ((array->is_inited) && (idx >= 0u && idx < array->size)) {
        printf("IDX %ld\n", idx * array->data_len);
        out = &(array->data[idx * array->data_len]);
    }

    return (void *)out;
}

/**
 * @brief Set data at idx position
 */
bool array_set(array_t *array, size_t idx, void *data)
{
    bool out = false;

    /* check if idx exceeds array space */
    if (idx < array->capacity) {
        /* set the value */
        for (size_t i = 0; i < array->data_len; i++) {
            array->data[(idx * array->data_len) + i] = ((uint8_t *)data)[i];
        }

        /* increase size if array idx out of bounds */
        if (idx >= array->size) {
            array->size = idx;
        }

        out = true;
    }

    return out;
}