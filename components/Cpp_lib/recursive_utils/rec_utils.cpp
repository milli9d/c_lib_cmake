#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "rec_utils.hpp"

namespace cpp_lib
{

    static void print_bin_r(uint64_t n);
    static bool can_sum_r(std::vector<int> &arr, int target, std::unordered_map<int, bool> &map);

    /**
     * @brief Recursively print a number in binary format
     * @param n
     */
    static void print_bin_r(uint64_t n)
    {
        if (n == 0) {
            return;
        }

        char temp = (n % 2 == 1) ? '1' : '0';
        print_bin_r(n / 2);
        printf("%c", temp);
    }

    /**
     * @brief Accessor for print bin
     * @param n
     */
    void print_bin(uint64_t n)
    {
        printf("0x%lx in binary : 0b", n);
        print_bin_r(n);
        printf("\n");
    }

    /**
     * @brief Recursively reverse a string
     * @param str
     * @return
     */
    std::string reverse_str_r(std::string str)
    {
        /* terminating condition */
        if (str == "" || str.length() == 1u) {
            return str;
        }

        return reverse_str_r(str.substr(1)) + str[0];
    }

    /**
     * @brief Recursively check if string is a palindrome
     * @param str
     * @return
     */
    bool is_palindrome_r(std::string str)
    {
        /* terminating condition */
        if (str == "" || str.length() == 1u) {
            return true;
        }

        /* if first and last chars match then continue */
        if (str.front() == str.back()) {
            /* forward substring from next char to last char - 1u (i.e 2 characters smaller) */
            return is_palindrome_r(str.substr(1u, str.length() - 2u));
        }

        return false;
    }

    /**
     * @brief Sum of n natural numbers
     * @param top 
     * @return 
     */
    uint64_t sum_nums_r(uint32_t top)
    {
        if (top <= 0u) {
            return top;
        }

        return top + sum_nums_r(top - 1u);
    }

    typedef std::unordered_map<uint32_t, uint64_t> fib_map;

    /**
     * @brief Generate the sum of fibonacci series till n
     * @param n
     * @return
     */
    uint64_t fib_r(uint32_t n)
    {
        static fib_map map;

        /* terminating condition */
        if (n <= 1u) {
            return n;
        }

        /* if already in memory then find use that value */
        if (map.find(n) != map.end()) {
            return map.at(n);
        }

        /* else calculate value and memoize */
        uint64_t out = fib_r(n - 1u) + fib_r(n - 2u);
        map.insert({n, out});

        return out;
    }

    /**
     * @brief
     * @param arr
     * @param target
     * @return
     */
    static bool can_sum_r(std::vector<int> &arr, int target, std::unordered_map<int, bool> &map)
    {
        if (map.find(target) != map.end()) {
            return map.at(target);
        }

        /* success case */
        if (target == 0) {
            return true;
        }

        if (target < 0) {
            return false;
        }

        bool out = false;

        for (int i : arr) {
            int rem = target - i;
            out |= can_sum_r(arr, rem, map);
        }

        map.insert({target, out});
        return out;
    }

    /**
     * @brief Return if array can add up to target
     * @param arr 
     * @param target 
     * @return 
     */
    bool can_sum(std::vector<int> &arr, int target)
    {
        std::unordered_map<int, bool> map{};

        printf("Can Sum? [ ");
        for(int i : arr) {
            printf("%d ", i);    
        }
        printf("] Target = %d\n", target);

        return can_sum_r(arr, target, map);
    }
}