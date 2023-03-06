/**
 * @brief Common Recursive Algorithms TB
 *
 *
 */
#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <unordered_map>

namespace cpp_lib
{
    /**
     * @brief Accessor for print bin
     * @param n
     */
    void print_bin(uint64_t n);

    /**
     * @brief Recursively reverse a string
     * @param str
     * @return
     */
    std::string reverse_str_r(std::string str);

    /**
     * @brief Recursively check if string is a palindrome
     * @param str
     * @return
     */
    bool is_palindrome_r(std::string str);

    /**
     * @brief Sum of n natural numbers
     * @param top
     * @return
     */
    uint64_t sum_nums_r(uint32_t top);

    /**
     * @brief Generate the sum of fibonacci series till n
     * @param n
     * @return
     */
    uint64_t fib_r(uint32_t n);

    /**
     * @brief Return if array can add up to target
     * @param arr 
     * @param target 
     * @return 
     */
    bool can_sum(std::vector<int> &arr, int target);
}

/**
 * @brief 
 */
class grid_traveler
{
private:
    typedef struct row_col_s
    {
        int32_t rows;
        int32_t columns;
    } row_col_t;

    row_col_t _sz{};
    row_col_t _pos{};

public:
    grid_traveler(size_t rows, size_t columns)
    {
        _sz.rows = rows;
        _sz.columns = columns;

        _pos.columns = 0u;
        _pos.rows = 0u;

        printf("Instantiated grid traveler [%d x %d] grid.\n", _sz.rows, _sz.columns);
    }

    void set_pos(size_t x, size_t y)
    {
        if (x > _sz.rows || y > _sz.columns) {
            throw std::out_of_range("Position out of range.");
        }
        _pos.rows = x;
        _pos.columns = y;

        printf("Updated grid traveler position [%d , %d].\n", _pos.rows, _pos.columns);
    }


    /**
     * @brief Return number of ways to travel to x,y from current pos
     * @param x 
     * @param y 
     * @return 
     */
    uint32_t count_ways(size_t x, size_t y)
    {
        static std::unordered_map<std::string, uint32_t> ways_map;

        std::string id = std::to_string(x) + "," + std::to_string(y);

        /* search in memoized */
        if (ways_map.find(id) != ways_map.end()) {
            return ways_map.at(id);
        }

        /* if reached bounds of grid */
        if ((x < 0 || y < 0) || (x > _sz.rows || y > _sz.columns)) {
            return 0u;
        }

        /* if found node then add to number of ways */
        if (x == _pos.rows && y == _pos.columns) {
            return 1u;
        }

        uint32_t out = count_ways(x, y - 1) +
                       count_ways(x - 1, y);

        ways_map.insert({id, out});

        return out;
    }



};