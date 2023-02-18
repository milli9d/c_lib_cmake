/**
 * @author Milind Singh
 * @date 02/14/2023
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

static void log_ques(void)
{
    /* log question */
    printf("2.1 Remove Dups!\n" 
    "Write code to remove duplicates from an unsorted linked list.\n"
    "FOLLOW UP\n"
    "How would you solve this problem if a temporary buffer is not allowed?\n" );
}

typedef struct node_s {
    node_t *next;
    uint32_t data;
} node_t;

int main()
{
    log_ques();

    char str[50];

    printf("Input String : ");

    // all_char_unique(str) ? printf("Yes\n") : printf("No\n");

    return 0;
}