/**
 * @brief Common Recursive Algorithms TB
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "linked_list.h"
#include "rec_utils.hpp"


void print_tf(bool condition) {
    condition ? printf("True\n") : printf("False\n"); 
}


void demo_run()
{
    /* linked list demos */
    node_t *new_list = NULL;

    fill_list_r(&new_list, 30, 2);

    print_list(new_list);

    /* numeric values demos */
    uint64_t val = 0xdeadbeef;
    cpp_lib::print_bin(val);

    printf("Sum of natural nums till %ld is %ld\n", val, cpp_lib::sum_nums_r(0u));

    for (uint64_t i = 0; i < 50u; i++) {
        printf("fib[%ld] = %ld \n", i, cpp_lib::fib_r(i));
    }

    /* string value demos */
    printf("%s\n", cpp_lib::reverse_str_r("raceCar").c_str());

    printf("is palindrome = %s\n", cpp_lib::is_palindrome_r("tacOcat") == true ? "True" : "False");
}

void grid_traveler_demo()
{
    grid_traveler test = grid_traveler(128u, 128u);

    test.set_pos(10u, 10u);
    std::cout << test.count_ways(11u, 30u) << std::endl;
    std::cout << test.count_ways(25u, 99u) << std::endl;
    std::cout << test.count_ways(15u, 66u) << std::endl;
}



int main()
{
    // grid_traveler_demo();

    std::vector<int> test = {1,5,10,25,50,100};
    print_tf(cpp_lib::can_sum(test, 47010));
    print_tf(cpp_lib::can_sum(test, 25400));

    return 0;
}