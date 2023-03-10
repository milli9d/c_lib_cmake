#include <stdio.h>
#include <stdint.h>
#include <iostream>

#include "linked_list.h"

int main(int argc, char **argv)
{
    node_t *test = NULL;

    int32_t rc = ERR_OK;

    for (int i = 10; i >= 0; i--) {
        rc = list_push_front(&test, i);
    }

    std::cout << list_size(NULL) << std::endl;
    std::cout << list_size(test) << std::endl;

    list_print(test);

    std::cout << "Delete 0" << std::endl;
    list_delete(&test, 0u);
    list_print(test);

    std::cout << "Delete 3" << std::endl;
    list_delete(&test, 3u);
    list_print(test);

    std::cout << "Delete end" << std::endl;
    list_delete(&test, list_size(test) - 1u);
    list_print(test);

    std::cout << "Delete end + 1u" << std::endl;
    list_delete(&test, list_size(test));
    list_print(test);

    list_insert(&test, 0u, 32u);
    list_print(test);

    list_insert(&test, 5u, 64u);
    list_print(test);

    list_insert(&test, list_size(test), 128u);
    list_print(test);

    list_insert(&test, list_size(test) + 1u, 128u);
    list_print(test);

    list_reverse_i(NULL);
    list_print(test);

    list_reverse_i(&test);
    list_print(test);

    node_t* test_1_element = NULL;
    list_push_front(&test_1_element, 10u);

    list_reverse_i(&test_1_element);
    list_print(test_1_element);

    // print_list(test);

    // reverse_r(&test);
    // print_list(test);

    // reverse_i(&test);
    // print_list(test);

    // printf("Found node - %d\n", (search_val(test, 64u))->val);

    // empty_list(&test);
    // print_list(test);

    // node_t *search = search_val(test, 32u);
    // if (search)
    // {
    //     printf("Found node - %d\n", search->val);
    // }

    return 0;
}