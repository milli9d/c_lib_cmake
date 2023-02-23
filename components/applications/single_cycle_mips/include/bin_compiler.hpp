/**
 * @brief ASM-Binary Compiler for MIPS
 *
 */
#pragma once

#include <iostream>
#include <filesystem>
#include <fcntl.h>

namespace mips
{
    /**
     * @brief Binary compiler for MIPS ISA
    */
    class bin_compiler
    {
    public:
        /* constructor/destructor */
        bin_compiler() = delete;
        bin_compiler(std::filesystem::path in, std::filesystem::path out);
        ~bin_compiler();

    private:
        /* private data */
        std::filesystem::path _in;
        std::filesystem::path _out;

        int _fd;

        /* private API */
    }; 

}