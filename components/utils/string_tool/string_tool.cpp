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

#include "string_tool.hpp"

namespace utils
{

    /**
     * @brief Swap two characters
     *
     * @param   a,b   character pointers
     */
    static void swap(char *a, char *b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }

    /**
     * @brief Get the string length
     *
     * @return  length of null terminated string
     * @throw   std::runtime_error    invalid string
     */
    size_t string_tool::strlen(const char *in)
    {
        /* sanity checks */
        if (in == NULL) {
            throw std::runtime_error("Invlaid string.");
        }

        size_t out = 0u;

        /* make character iterator */
        const char *ptr = &in[0u];
        /* iterate till you find the terminating character */
        while (*(ptr++) != '\0') {
            out++;
        }

        return out;
    }

    /**
     * @brief Reverse a string in place
     *
     */
    const char *string_tool::reverse_str(char *in)
    {
        /* sanity check */
        if (in == NULL) {
            throw std::runtime_error("String pointer is invalid.");
        }

        size_t sz = string_tool::strlen(in);
        for (size_t i = 0u; i < (sz / 2); i++) {
            utils::swap(&in[i], &in[sz - i - 1u]);
        }

        return in;
    }

    /**
     * @brief Tell if charcter is a digit 
     * 
     */
    bool string_tool::is_digit(const char &in)
    {
        /* decide if a digit */
        if ( in >= '0' && in <= '9') {
            return true;
        }

        return false;
    }

    /**
     * @brief Find the first occurence of a number
     */
    static void find_first_num(const char *in, int &first, int &last)
    {
        /* sanity check */
        if (in == NULL) {
            return;
        }

        int f = -1;
        int l = -1;

        size_t len = string_tool::strlen(in);

        /* find lower bound */
        for (size_t i = 0u; i < len; i++) {
            /* if digit then find bounds */
            if (string_tool::is_digit(in[i]) == true) {
                /* find first */
                if (f == -1) {
                    f = i;
                    break;
                }
            }
        }

        /* find upper bound */
        for (size_t i = f; i < len; i++) {
            /* if not digit then mark as bound */
            if (string_tool::is_digit(in[i]) == false) {
                l = i - 1;
                break;
            }
            /* if string ended and still digit then len is upper bound */
            if (i == len -1) {
                l = len;
            }
        }

        first = f;
        last = l;
    }

    /**
     * @brief Convert a string to integer
     * 
     */
    uint64_t string_tool::atoi(const char *in)
    {
        /* sanity check */
        if (in == NULL) {
            throw std::runtime_error("String pointer is invalid.");
        }

        uint64_t out = 0u;
        size_t sz = strlen(in);

        /* 
            Rules:
            1. Whitespaces and zeroes are ignored
            2. First number is taken
            3. First delimiter [any character] is the end of number
            4.
        
        */

        int first = -1, last = -1;
        find_first_num(in, first, last);

        std::cout << "IN:[" << in << "]F:" <<  first << " L:" << last <<std::endl;

        return out;
    }

}