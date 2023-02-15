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
    printf("Q> Is Unique:\n"
           "\tImplement an algorithm to determine if a string has all unique characters.\n"
           "\tWhat if you cannot use additional data structures?\n");
}

#define NUM_CHARACTERS_ASCII    128u

/**
 * @brief Check if all characters are unique by tracking each character by a bit
*/
static bool all_char_unique(const char* string)
{
    /* sanity check */
    if (string == NULL)
    {
        printf("Invalid string.\n");
        return false;
    }

    /* make tracker for characters */
    bool tracker[NUM_CHARACTERS_ASCII] = {false};

    /* iterate over the string and fill trackers */
    const char *itr = &string[0];
    while (*itr != '\0') {
        /* if already seen , then not unique */
        if (tracker[(uint8_t)*itr]) {
            printf("\n");
            printf("Duplicate: %c\n", *itr);
            return false;
        }
        /* else marked seen */
        tracker[(uint8_t)*itr] = true;
        printf("%c", *itr);
        itr++;
    }
    printf("\n");
    return true;
}

int main()
{
    log_ques();

    char str[50];

    printf("Input String : ");
    scanf("%s", str);

    all_char_unique(str) ? printf("Yes\n") : printf("No\n");

    return 0;
}