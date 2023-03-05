/**
 * @brief Common Recursive Algorithms TB
 *
 *
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string>

namespace cpp_lib
{
    /**
     * @brief Accessor for print bin
     * @param n
     */
    void print_bin(uint64_t n);

    /**
     * @brief Recursively reverse a string
     * @param str
     * @return
     */
    std::string reverse_str_r(std::string str);

    /**
     * @brief Recursively check if string is a palindrome
     * @param str
     * @return
     */
    bool is_palindrome_r(std::string str);

    /**
     * @brief Sum of n natural numbers
     * @param top
     * @return
     */
    uint64_t sum_nums_r(uint32_t top);

    /**
     * @brief Generate the sum of fibonacci series till n
     * @param n
     * @return
     */
    uint64_t fib_r(uint32_t n);
}