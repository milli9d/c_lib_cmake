/**
 * @author Milind Singh
 * @date 02/14/2023
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int arr1[4][4] = {{1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12},
                  {13, 14, 15, 16}};

/**
 * @brief Log the question
 */
static void log_ques(void)
{
    /* log question */
    printf("Q> Rotate Matrix:\n\tGiven an image represented by an NxN matrix, where each pixel in the image is 4"
           "bytes, write a method to rotate the image by 90 degrees. Can you do this in place?\n");
}

/**
 * @brief Swap two integers in place
 *
 * @param a
 * @param b
 */
static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Transpose an n x n matrix
 *
 * @param n
 * @param arr
 * @return true
 * @return false
 */
static bool transpose_matrix(int n, int arr[n][n])
{
    /* sanity check */
    if (n == 0 || arr == NULL || arr[0] == NULL) {
        return false;
    }

    /* swap diagonal [upper triangle] with other [lower triangle] */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(&arr[i][j], &arr[j][i]);
        }
    }

    return true;
}

/**
 * @brief Reverse an array in-place
 *
 * @param size
 * @param arr
 * @return true
 * @return false
 */
static bool reverse_arr(int size, int arr[size])
{
    if (size == 0 || arr == NULL) { return false; }

    /* swap half the array */
    for (int i = 0; i < size / 2; i++) {
        swap(&arr[i], &arr[size - i - 1u]);
    }

    return true;
}

/**
 * @brief Rotate an nxn matrix right by n_rot x 90 deg
 *
 * @param n_rot
 * @param n
 * @param arr
 * @return true
 * @return false
 */
static bool rotate_arr_right(int n_rot, int n, int arr[n][n])
{
    /* sanity check */
    if (n_rot == 0 || n == 0 || arr == NULL || arr[0] == NULL)
    {
        return false;
    }

    /* rotate by n_rot times */
    for (int i = 0; i < n_rot; i++)
    {
        /* rotate by 90 deg [left] */
        transpose_matrix(n, arr);
        for (int j = 0; j < n; j++)
        {
            reverse_arr(n, arr[j]);
        }
    }
    return true;
}

/**
 * @brief Print a 2D n x n matrix
 *
 * @param n
 * @param arr
 */
static void printArr(int n, int arr[n][n])
{
    /* sanity check */
    if (arr == NULL || arr[0] == NULL)
    {
        return;
    }

    /* print out matrix */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    log_ques();
    printf("Original:\n");
    printArr(4, arr1);

    printf("Transposed:\n");
    transpose_matrix(4, arr1);
    printArr(4, arr1);

    printf("Rotated Right 90deg:\n");
    rotate_arr_right(1, 4, arr1);
    printArr(4, arr1);

    return 0;
}