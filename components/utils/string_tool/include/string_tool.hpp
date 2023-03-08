/**
 * @brief File Map Utility
 *
 * This utility allows to memory map a file and read/write it's content
 * in various data formats.
 *
 * @author Milind Singh
 *
 */

#pragma once

#include <iostream>
#include <filesystem>
#include <cstdbool>

namespace utils
{
    class string_tool
    {
    public:
        static uint64_t atoi(const char *in);
        static size_t strlen(const char *in);
        static const char *reverse_str(char *in);
        static bool is_digit(const char &in);

    private:
    };

}