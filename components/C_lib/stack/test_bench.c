#include <stdio.h>
#include <stdint.h>

#include "stack.h"
#include "linked_list.h"

int main(int argc, char **argv)
{

    stack_t test = {0u};

    for (int i = 0u; i < 10u; i++) {
        stack_push(&test, i * 10u);
    }

    stack_pop(&test);
    stack_pop(&test);
    stack_pop(&test);

    node_t* p_temp = stack_peek(&test);
    p_temp->val = 99u;

    print_list_rf(test.top);

    stack_reverse(&test);
    print_list_rf(test.top);
    
    printf("Stack demo finished size = %ld.\n", test.size);
    return 0;
}