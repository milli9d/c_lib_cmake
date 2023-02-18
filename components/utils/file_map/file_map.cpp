/**
 * @brief File Map Utility
 *
 * This utility allows to memory map a file and read/write it's content
 * in various data formats.
 *
 * @author Milind Singh
 *
 */

#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <cstdbool>
#include <errno.h>

#include "include/file_map.hpp"

namespace utils
{

    size_t file_map::read_sz(void)
    {
        /* read file size */
        struct stat st;
        fstat(fileno(_fd), &st);
        return (size_t)st.st_size;
    }

    /**
     * @brief Read an UINT8_T from the file starting at itr index
     */
    uint8_t file_map::rd_uint8(void)
    {
        uint8_t out = 0u;
        if (_itr) {
            out = *_itr;
            _itr++;
        }
        return out;
    }

    /**
     * @brief Read an UINT16_T from the file starting at itr index
     */
    uint16_t file_map::rd_uint16(void)
    {
        uint16_t out = 0u;
        if (_itr) {
            out = *_itr;
            _itr+=2;
        }
        return out;
    }

    /**
     * @brief Read an UINT32_T from the file starting at itr index
     */
    uint32_t file_map::rd_uint32(void)
    {
        uint32_t out = 0u;
        if (_itr) {
            out = *_itr;
            _itr+=4;
        }
        return out;
    }

    /**
     * @brief Print out all file contents
     *
     */
    void file_map::print_file(void)
    {
        printf("Printing File:\n\t=============\n"
               "%s\n\t=============\n"
               "End of File\n",
               _mem);
    }

    /**
     * @brief Get raw pointer to data
     */
    unsigned char *const file_map::get_mem(void)
    {
        return _mem;
    }

    /**
     * @brief Get data size
     */
    size_t file_map::size(bool update)
    {
        if (update) {
            struct stat st;
            fstat(fileno(_fd), &st);
            _sz = (size_t)st.st_size;
        }
        return _sz;
    }

    /**
     * @brief Default Constructor
     *
     * Open a file and map it to memory for this class instance
     */
    file_map::file_map(std::filesystem::path file)
    {
        /* open file */
        if ((_fd = fopen(file.c_str(), "ab+")) == NULL) {
            throw std::runtime_error("Error: Could not open file!");
        }

        /* get file size */
        _sz = read_sz();

        /* map to memory */
        if ((_mem = (unsigned char *)mmap(NULL, _sz, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(_fd), 0u)) == MAP_FAILED) {
            printf("ERROR %d\n", errno);
            throw std::runtime_error("Memory mapping file failed.");
        }

        /* set iterator to beginning of file */
        _itr = _mem;

        printf("Constructed file_map.\n"
               "Path = %s\n"
               "Size = %ld\n",
               file.c_str(), _sz);
    }

    /**
     * @brief Destructor
     */
    file_map::~file_map()
    {
        /* flush file buffer */
        msync(_mem, _sz, MS_SYNC);

        /* unmap file */
        munmap(_mem, this->size(true));
        
        /* close file descriptor */
        fclose(_fd);
    }

}