/**
 * @brief LRU Cache Class
 *
 * @author Milind Singh
 *
 */

#pragma once

#include <cstdio>
#include <iostream>
#include <cstdbool>

namespace cache
{

    class LRU_cache
    {
    private:
    public:
        /**
         * @brief Configuration for a cache class
         */
        typedef struct cache_conf_s
        {
            size_t block_sz;
            size_t set_sz;
            size_t cache_sz;
        } cache_conf_t;

        /* default constructor */
        LRU_cache() = delete;

        /* custom constructor */
        LRU_cache(cache_conf_t &conf);
    };
}