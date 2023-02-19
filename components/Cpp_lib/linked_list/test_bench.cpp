#include <stdio.h>
#include <stdint.h>

#include "include/linked_list.hpp"

int main(int argc, char **argv)
{

    cpp_lib::byte_list test;

    for (unsigned int i = 0u; i <= 5u; i++) {
        test.push_front(i);
        test.append(i);
    }
    test.print();

    test.remove(0u);
    test.print();

    test.remove(test.size() - 2u);
    test.print();

    test.remove(test.size() - 1u);
    test.print();

    test.insert(0u, 8u);
    test.print();

    test.insert(5u, 64u);
    test.print();

    test.insert(test.size(), 255u);
    test.print();

    // reverse_r(&test);
    // print_list(test);

    // reverse_i(&test);
    // print_list(test);

    // printf("Found node - %d\n", (search_val(test, 64u))->val);

    // empty_list(&test);
    // print_list(test);

    // node_t *search = search_val(test, 32u);
    // if (search) {
    //     printf("Found node - %d\n", search->val);
    // }
    return 0;
}