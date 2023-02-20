/**
 * @author Milind Singh
 * @date 1/29/2023
 *
 * @brief CPP Static Array Library
 *
 */

#pragma once

#include <iostream>
#include <cstdio>
#include <cstdbool>
#include <cstring>
#include <stdexcept>
#include <ostream>

namespace cpp_lib
{

    template <typename T, size_t S>
    class static_array
    {
    private:
        /* private data members */
        T *_mem{};
        size_t _sz{};

        /* private API */

    public:
        /**
         * @brief Default Constructor
         *
         * Initialize array memory and populate data members
         */
        static_array(void)
        {
            /* allocate enough memory for S number of T instances */
            _mem = (T *)malloc(sizeof(T) * S);
            _sz = S;
        }

        /**
         * @brief Constructor which fills data with supplied value
         *
         * @param fill
         */
        static_array(T &fill)
        {
            static_array();
            /* TODO : use std::fill with iterator */
        }

        class iterator
        {
        public:
            iterator(T *ref) : _itr(ref) {}

            /* Overload * operator */
            T &operator*()
            {
                return *_itr;
            }

            /* Overload ++x operator */
            iterator &operator++()
            {
                _itr++;
                return *this;
            }

            /* Overload x++ operator */
            iterator &operator++(int)
            {
                iterator &ref = *this;
                ++(*this);
                return ref;
            }

            /* Overload --x operator */
            iterator &operator--()
            {
                _itr--;
                return *this;
            }

            /* Overload x-- operator */
            iterator &operator--(int)
            {
                iterator &ref = *this;
                --(*this);
                return ref;
            }

            /* Overload == operator */
            bool operator==(const iterator &other) const
            {
                return (_itr == other._itr);
            }

            /* Overload != operator */
            bool operator!=(const iterator &other) const
            {
                return (_itr != other._itr);
            }

        private:
            /* storage for iterator pointer */
            T *_itr = nullptr;
        };

        /**
         * @brief Get begin iterator
         * @return 
         */
        iterator begin()
        {
            return iterator(_mem);
        }

        /**
         * @brief Get end iterator
         * @return 
         */
        iterator end()
        {
            return iterator(_mem + _sz);
        }

        /**
         * @brief Get a reference to the value at idx
         * @param idx
         * @return
         */
        T &at(size_t idx)
        {
            if (idx >= _sz)
            {
                throw std::out_of_range("Invalid array index.");
            }
            return *(_mem + idx);
        }

        /**
         * @brief Overload the << operator
         *
         * Pretty print this array
         */
        friend std::ostream &operator<<(std::ostream &os, const static_array<T, S> &m)
        {
            for (int i = 0; i < m._sz; i++)
            {
                os << "idx[" << i << "] = " << m._mem[i] << "\n";
            }
            return os;
        }

        /**
         * @brief Overload the [] operator
         */
        T &operator[](unsigned int idx)
        {
            if (idx >= _sz)
            {
                throw std::out_of_range("Invalid array index.");
            }
            return *(_mem + idx);
        }
    };
}
