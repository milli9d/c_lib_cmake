/**
 * @brief Generic Test Bench to experiment and learn with components
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/* component includes */
#include "linked_list.h"


int main(int argc, char **argv)
{
    node_t *new_list = NULL;

    append_node(&new_list, 1u);
    append_node(&new_list, 2u);
    append_node(&new_list, 3u);
    append_node(&new_list, 4u);
    append_node(&new_list, 5u);
    append_node(&new_list, 6u);

    print_list(new_list);

    return 0;
}