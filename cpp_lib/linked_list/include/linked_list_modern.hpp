/**
 * @file linked_list.hpp
 *
 * @brief Array List
 *
 */
#pragma once

#include <iostream>
#include <cstring>
#include <memory>
/**
 * TODO:
 * 1. Reverse Iteration and recursion
 * 2. Sort
 * 3. Merge
 * 4. Remove duplicates
 * 5. Find middle
 * 6. Find nth from end
 * 7. Find nth from beginning
 * 8. Find loop
 * 9. Remove loop
 * 10. Detect loop
 * 11. Detect intersection
 * 12. Find intersection
 * 13. Find intersection point
 */

namespace cpp_lib {

template<typename T>
class linked_list
{
  public:
    /**
     * @brief Node type definition
     */
    typedef struct _node_s {
        std::shared_ptr<struct _node_s> next;
        T val;
    } node_s;

  private:
    /* ===================================================================== */
    /* Private type defines */
    /* ===================================================================== */

    typedef std::shared_ptr<node_s> node_pointer_t;
    typedef const node_pointer_t const_node_pointer_t;

    /* ===================================================================== */
    /* Private data members */
    /* ===================================================================== */

    size_t _sz = 0u;
    node_pointer_t _head{};

    /**
     * @brief Allocate a new node
     * @param val
     * @return
     */
    node_pointer_t new_node(T& val)
    {
        /* fill node */
        node_pointer_t ptr = std::make_shared<T>();
        ptr->next = NULL;
        ptr->val = val;

        return ptr;
    }

  public:
    /* =================================================================== */
    /* Constructors/Destructors */
    /* =================================================================== */

    /**
     * @brief Default constructor
     */
    linked_list() : _head(NULL), _sz(0u) {}

    /**
     * @brief Default destructor
     */
    ~linked_list() {}

    /* =================================================================== */
    /* Iterator overloads */
    /* =================================================================== */

    /**
     * @brief Iterator
     */
    class iterator
    {
      private:
        node_pointer_t _ptr = nullptr;

      public:
        /* constructora */
        iterator() : _ptr(nullptr){};
        iterator(const node_pointer_t& ptr) : _ptr(ptr){};

        /* ================================================================= */
        /* Opeartor Overloads */
        /* ================================================================= */
    };

    /* ===================================================================== */
    /* Public API */
    /* ===================================================================== */

    /* ===================================================================== */
    /* Public API */
    /* ===================================================================== */

    /**
     * @brief Push to the front of the list
     * @param val
     */
    void push_front(const T& val)
    {
        /* allocate new node */
        node_pointer_t _node = new_node(val);
        if (_node == NULL) {
            throw std::bad_alloc();
        }

        /* if head is NULL , set up head */
        if (_head == NULL) {
            _head = _node;
            _tail = _node;
        } else {
            /* replace head */
            node_pointer_t _orig_head = _head;
            _head = _node;
            _node.get()->next = _orig_head;
        }

        /* update size */
        _sz++;
    }

    /**
     * @brief Push to the end of the list
     * @param val
     */
    void push_back(const T& val)
    {
        /* allocate new node */
        node_pointer_t _node = new_node(val);

        /* if head is null , replace head */
        if (_head.get() == NULL) {
            _head = _node;
        } else {
            /* traverse to the end of the list */
            node_pointer_t _ptr = _head;
            while (_ptr->next != NULL) {
                _ptr = _ptr.get()->next;
            }

            /* attach node */
            _ptr.get()->next = _node;

            /* update tail */
            _tail = _node;

            /* update size */
            _sz++;
        }
    }

    /**
     * @brief Insert at index
     * @param val   Value to insert
     * @param idx   Index to insert at
     */
    void insert(const T& val, size_t idx)
    {
        /* check if index is out of range */
        if (idx > _sz) {
            throw std::out_of_range("Index out of range");
        }

        /* allocate new node */
        node_pointer_t _node = new_node(val);

        /* if head is null , replace head */
        if (_head.get() == NULL) {
            _head = _node;
        } else {
            /* traverse to node before idx */
            node_pointer_t _ptr = _head;
            while (_ptr != NULL && idx > 1) {
                _ptr = _ptr.get()->next;
                idx--;
            }

            /* gather pointers */
            node_pointer_t _next = _ptr.get()->next;

            /* attach node */
            _ptr.get()->next = _node;

            /* link back next */
            _node.get()->next = _next;

            /* update size */
            _sz++;
        }
    }

    /**
     * @brief Delete node at idx
     * @param idx
     */
    void delete_idx(size_t idx)
    {
        /* check if idx is out of range */
        if (idx > _sz) {
            throw std::out_of_range("Index out of range");
        }

        /* if head is empty , return */
        if (_head == NULL) {
            throw std::invalid_argument("List is empty");
        }

        /* navigate to pointer before idx to be deleted */
        node_pointer_t ptr = _head;
        while (ptr != NULL && idx-- > 1u) {
            ptr = ptr->next;
        }

        /* attach future pointer */
        node_pointer_t next = nullptr;
        if (ptr->next) {
            next = ptr->next->next;
        }

        /* smart pointer , no need to delete , just invalidate all references */
        ptr->next = next;

        /* update size */
        _sz--;
    }

    /**
     * @brief Count occurrences of particular element node
     * @param val
     * @return
     */
    size_t count_occurrence(const T& val)
    {
        /* if list is invalid throw exception */
        if (_head == nullptr) {
            throw std::invalid_argument("Invalid head pointer");
        }

        /* if list is empty, return 0 */
        if (_sz == 0u) {
            return 0u;
        }

        /* traverse and count matches */
        node_pointer_t ptr = _head;
        size_t count = 0u;
        while (ptr != NULL) {
            /* found match */
            if (ptr->val == val) {
                count++;
            }

            /* move forward */
            ptr = ptr->next;
        }

        return count;
    }
};

} // namespace cpp_lib