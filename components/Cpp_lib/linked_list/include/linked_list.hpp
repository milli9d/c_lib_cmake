/**
 * @brief Linked List
 *
 * @author Milind Singh
 *
 * @date 2/14/2023
 */

#pragma once

#include <iostream>
#include <cstdio>

typedef uint8_t list_data_t;

namespace cpp_lib
{
    class byte_list
    {
    public:
        /* constructor */
        byte_list();

        /* node definition for this linked list */
        typedef struct node_s {
            list_data_t val;
            struct node_s *next;
        } node_t;

        /* data operations */
        bool pop_front(void);
        void push_front(list_data_t val);
        void append(list_data_t val);
        bool remove(size_t idx);
        bool insert(size_t idx, list_data_t val);

        /* collection operations */
        void i_reverse(void);
        void r_reverse(void);

        /* meta operations */
        void print(void);
        size_t size(void);

    private:
        /* list meta-data */
        size_t _sz = 0u;

        node_t *_head{};
        node_t *_tail{};

        /* private API */
        node_t *new_node(list_data_t val);
    };

}
