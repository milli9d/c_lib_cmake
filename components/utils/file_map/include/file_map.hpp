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
    class file_map
    {
    public:
        /* constructor */
        file_map() = delete;
        file_map(std::filesystem::path file);
        
        /* destructor */
        ~file_map();

        /* public API */
        void print_file(void);
        unsigned char* const get_mem(void);
        size_t size(bool update);

        /* iterator operations */
        void reset_itr(void);
        bool rewind(size_t offset);
        void seek(size_t index);

        /* read */
        uint8_t rd_uint8(void);
        uint16_t rd_uint16(void);
        uint32_t rd_uint32(void);
        uint64_t rd_uint64(void);

        /* write */


        /* operators */


    private:

        /* private data members */
        unsigned char* _mem;
        FILE* _fd{};
        size_t _sz{};
        unsigned char* _itr;

        /* private API */
        size_t read_sz(void);
    };

}