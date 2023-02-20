/**
 * @brief Linked List
 *
 * @author Milind Singh
 *
 * @date 2/1/2023
 */

#include <iostream>
#include <cstdio>

#include "include/linked_list.hpp"

namespace cpp_lib
{
    /* ======================================================== Private API */

    /**
     * @brief Make a new node with supplied value
     *
     * @param val       Value to be filled in the node
     */
    byte_list::node_t *byte_list::new_node(list_data_t val)
    {
        byte_list::node_t *out = (node_t *)malloc(sizeof(node_t));

        out->next = NULL;
        out->val = val;

        return out;
    }

    /* ======================================================== Public API */

    /**
     * @brief Append to the end of the list
     */
    void byte_list::append(list_data_t val)
    {
        /* make a new node */
        node_t *node = new_node(val);

        if (_tail != NULL) {
            _tail->next = node;
        } else {
            if (_head == NULL) {
                /* if HEAD is empty, then assign new node to head */
                _head = node;
            } else {
                /* if not empty, then traverse to the end of the list */
                node_t *itr = _head;
                while (itr != NULL && itr->next != NULL) {
                    itr = itr->next;
                }
                itr->next = node;
            }
        }
        
        /* update meta-data */
        _tail = node;
        _sz++;
    }

    /**
     * @brief Push to the front of the list
     * 
     * @param val 
     */
    void byte_list::push_front(list_data_t val)
    {
        /* make new node */
        node_t* node = new_node(val);

        /* attach rest of the list to node */
        if(_head != NULL) {
            node->next = _head;
        }

        /* replace HEAD */
        _head = node;
        _sz++;
    }

    /**
     * @brief Pop the front element from the list
     * 
     * @return true     delete success
     * @return false    delete failed
     */
    bool byte_list::pop_front()
    {
        /* return if list already empty */
        if (_head == NULL) {
            return false;
        }

        /* store delete address */
        node_t *to_del = _head;

        /* switch HEAD */
        _head = _head->next;

        /* free allocation */
        free(to_del);
        to_del = NULL;
        _sz--;

        return true;
    }

    /**
     * @brief Remove an element from the requested index
     * 
     * @param idx 
     * @return true     delete successful
     * @return false    delete failed
     */
    bool byte_list::remove(size_t idx) 
    {
        /* sanity check */
        if(idx >= _sz) {
            printf("deleteIndex %ld/%ld out of bounds.\n", idx, _sz);
            return false;
        }

        /* CASE: delete HEAD */
        if (idx == 0u) {
            return pop_front();
        }

        /* traverse to delete index - 1u */
        node_t* itr = _head;
        while (itr != NULL && itr->next != NULL && (idx--) > 1u) {
            itr = itr->next;
        }

        /* gather pointers */
        node_t* to_del = itr->next;
        node_t* rest = to_del->next;

        /* pop out node */
        itr->next = rest;

        /* update TAIL */
        if(to_del == _tail) {
            _tail = itr;
        }

        /* delete node from memory */
        printf("Deleting val %d\n", to_del->val);
        free(to_del);
        to_del = NULL;
        _sz--;

        return true;
    }

    /**
     * @brief Insert a value at index specified
     * 
     * @param idx       insert index [_sz is a valid value for append]
     * @param val       value to be inserted
     * @return true     success
     * @return false    failure
     */
    bool byte_list::insert(size_t idx, list_data_t val)
    {
        if(idx > _sz) {
            printf("InsertIndex out of bounds. %ld / %ld", idx, _sz);
            return false;
        }

        /* CASE: Insert at front */
        if(idx == 0u) {
            push_front(val);
            return true;
        }

        /* CASE: Insert at back */
        if(idx == _sz) {
            append(val);
            return true;
        }

        /* traverse to (writeIdx - 1u) */
        node_t* itr = _head;
        while(itr != NULL && itr->next != NULL && (idx--) > 1u) {
            itr = itr->next;
        }

        /* make new node */
        node_t* node = new_node(val);

        /* attach node to list; place rest of list after idx in node's next */
        node->next =  itr->next;
        itr->next = node;

        return true;
    }

    /**
     * @brief Get list size
     * 
     * @return size_t 
     */
    size_t byte_list::size(){
        return _sz;
    }

    /**
     * @brief Pretty print this list
     */
    void byte_list::print()
    {
        printf("HEAD->");

        /* if not empty, then traverse to the end of the list */
        byte_list::node_t *itr = _head;
        while (itr != NULL) {
            printf(" %d -->", itr->val);
            itr = itr->next;
        }

        printf("TAIL\n");
    }

    /**
     * @brief Default Constructor
     */
    byte_list::byte_list()
        : _head(NULL), _sz(0u)
    {
        fprintf(stdout, "Constructed byte list object.\n");
    }

}