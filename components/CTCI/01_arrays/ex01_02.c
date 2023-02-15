/**
 * @author Milind Singh
 * @date 02/14/2023
*/

#include <stdio.h>
#include <stdbool.h>

static void log_ques(void)
{
    /* log question */
    printf("Q> Is Unique:\n"
           "\tImplement an algorithm to determine if a string has all unique characters.\n"
           "\tWhat if you cannot use additional data structures?\n");
}

#define NUM_ALPHABETS       26u
#define NUM_UPPER_LOWER     (NUM_ALPHABETS * 2u)

/**
 * @brief Check if all characters are unique by 
*/
static bool all_char_unique(const char* string)
{
    bool tracker[NUM_UPPER_LOWER] = {false};

    return false;
}

int main()
{
    log_ques();

    const char* str = "Milind";

    printf("Input String : %s", str);

    if(all_char_unique(str)){
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}