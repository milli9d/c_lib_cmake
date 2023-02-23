/**
 * @brief HashMap Implementation
 *
 * @author Milind Singh
 */

#pragma once

#include <iostream>
#include <cstdio>
#include <cmath>

#include "circular_queue.hpp"

namespace cache
{

    template <typename T, size_t S, size_t N>
    class hash_map
    {
    public:
        hash_map()
        {
            _map = (c_queue<T, N> *)malloc(sizeof(c_queue<T, N>) * S);
        }

    private:
        size_t hash_func(uint32_t addr)
        {
            return 0u;
        }

        /* private data */
        c_queue<T, N> *_map;
        size_t _cap = S;
        size_t _q_sz = N;
    };

}