#include <iostream>
#include <unistd.h>
#include <filesystem>
#include <sys/mman.h>

#include "string_tool.hpp"

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

    std::cout << utils::string_tool::atoi("123 ") << std::endl;
    std::cout << utils::string_tool::atoi("+123 ") << std::endl;
    std::cout << utils::string_tool::atoi("-123 ") << std::endl;
    std::cout << utils::string_tool::atoi("0000123") << std::endl;
    std::cout << utils::string_tool::atoi("     123") << std::endl;
    std::cout << utils::string_tool::strlen("     123") << std::endl;

    char in[20] = "Milind";
    std::cout << utils::string_tool::reverse_str(in) << std::endl;

    return 0;
}