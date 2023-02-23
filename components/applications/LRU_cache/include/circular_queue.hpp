/**
 * @brief Circular Buffer Queue
 *
 * @author Milind Singh
 */

#pragma once

#include <iostream>
#include <cstdio>

namespace cache
{

    // FIFO Circular Buffer
    template <typename T, size_t S>
    class c_queue
    {
    public:
        /**
         * @brief Default Constructor
         */
        c_queue() : _cap(S)
        {
            /* allocate memory block */
            _mem = (T *)malloc(sizeof(T) * _cap);
        }

        /**
         * @brief Check if queue is empty
         * @return
         */
        bool is_empty()
        {
            return (_sz == 0u);
        }

        /**
         * @brief Check if queue is full
         * @return
         */
        bool is_full()
        {
            return (_sz == _cap);
        }

        /**
         * @brief Enqueue a value in the queue
         * @param val
         */
        void enqueue(const T &val)
        {
            /* check if queue is full */
            if (is_full())
            {
                throw std::out_of_range("List is full.\n");
            }

            /* enqueue */
            _mem[_tail] = val;
            _tail = (_tail + 1u) % _cap;
            _sz++;
        }

        /**
         * @brief Dequeue a value in the queue
         * @param val
         */
        const T dequeue()
        {
            T out{};

            /* check if queue is full */
            if (is_empty())
            {
                throw std::out_of_range("List is empty.\n");
            }

            /* dequeue */
            out = _mem[_head];
            _head = (_head + 1u) % _cap;
            _sz--;

            return out;
        }

        /**
         * @brief Pretty print queue
         */
        void print_queue()
        {
            std::cout << "HEAD ->";
            for (size_t i = _head; i < _head + _sz; i++)
            {
                std::cout << (T)_mem[i % _cap] << "-->";
            }
            std::cout << "TAIL\n";
        }

    private:
        /* private data */
        T *_mem{};
        size_t _sz{};
        size_t _cap{};

        /* trackers */
        size_t _head = 0u;
        size_t _tail = 0u;
    };
}