/**
 * @brief Common Sorting Algorithms TB
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string>

#include "linked_list.h"
#include "rec_utils.hpp"


int main()
{
    /* linked list demos */
    // node_t *new_list = NULL;

    // fill_list_r(&new_list, 30, 2);

    // print_list(new_list);

    /* numeric values demos */
    // uint64_t val = 0xdeadbeef;
    // cpp_lib::print_bin(val);

    // printf("Sum of natural nums till %ld is %ld\n", val, cpp_lib::sum_nums_r(0u));

    for (uint64_t i = 0; i < 35u; i++)
    {
        printf("%ld-> ", cpp_lib::fib_r(i));
    }

    /* string value demos */
    // printf("%s\n", cpp_lib::reverse_str_r("My name is Slim Shady").c_str());

    // printf("is palindrome = %s\n", cpp_lib::is_palindrome_r("tacocat") == true ? "True" : "False");

    return 0;
}