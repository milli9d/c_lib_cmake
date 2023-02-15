#include <stdio.h>
#include <stdint.h>

#include "include/double_linked_list.h"

int main(int argc, char **argv)
{
    dlist_t test = {0u};

    for (unsigned int i = 1u; i < 10u; i++) {
        push_node(&test, i);
        // append_node(&test, i);
    }

    print_list(&test, false);

    // delete_node(&test, 3u);
    // delete_node(&test, 0u);

    // print_list(test);

    // insert_node(&test, 0u, 32u); 
    // insert_node(&test, 4u, 64u);

    // print_list(test);

    // reverse_r(&test);
    // print_list(test);


    // reverse_i(&test);
    // print_list(test);

    // printf("Found node - %d\n", (search_val(test, 64u))->val);

    // empty_list(&test);
    // print_list(test);

    // dnode_t *search = search_val(test, 32u);
    // if (search) {
    //     printf("Found node - %d\n", search->val);
    // }
    return 0;
}