#include <iostream>
#include <unistd.h>
#include <filesystem>
#include <sys/mman.h>

#include "include/file_map.hpp"

int main(int argc, char **argv)
{
    /* parse file path from argument '-c' */
    char c = '\0';
    std::filesystem::path path = "/home/milind/repos/Interview/components/utils/file_map/testfile";
    // while ((c = getopt(argc, argv, "c:")) != -1) {
    //     switch (c) {
    //     case 'c':
    //         path = optarg;
    //         break;
    //     default:
    //         /* do nothing */
    //         break;
    //     }
    // }

    /* execute tests */
    utils::file_map test(path);
    test.print_file();

    unsigned char* itr = test.get_mem();

    uint8_t num_floats = *itr++;

    float arr[num_floats]{};

    for (int i = 0; i < num_floats; i++) {
        uint8_t *w_ptr = (uint8_t *)&arr[i];
        for (int j = 0; j < sizeof(float); j++) {
            w_ptr[j] = *itr++;
        }
    }

    printf("Num floats = %d\n", num_floats);

    for (int i = 0; i < num_floats; i++) {
        printf("Float[%d] = %.2f\n", i, arr[i]);
    }

    printf("Test Finished. Errno: %d File Size = %ld\n",errno, test.size(true));

    return 0;
}