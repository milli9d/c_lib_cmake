#include <stdio.h>
#include <stdint.h>

#include "include/linked_list.hpp"

int main(int argc, char **argv)
{
    node_t *test = NULL;

    for (unsigned int i = 0u; i < 10u; i++) {
        push_node(&test, i);
        append_node(&test, i);
    }
    print_list(test);

    delete_node(&test, 3u);
    delete_node(&test, 0u);

    print_list(test);

    insert_node(&test, 0u, 32u); 
    insert_node(&test, 4u, 64u);

    print_list(test);

    reverse_r(&test);
    print_list(test);


    reverse_i(&test);
    print_list(test);

    printf("Found node - %d\n", (search_val(test, 64u))->val);

    empty_list(&test);
    print_list(test);

    node_t *search = search_val(test, 32u);
    if (search) {
        printf("Found node - %d\n", search->val);
    }
    return 0;
}