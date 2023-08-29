/**
 * @file linked_list.hpp
 *
 * @brief Array List
 *
 */
#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <memory>

namespace cpp_lib {

template<typename T>
class linked_list
{
  public:
    /* =================================================================== */
    /* Public definitions */
    /* =================================================================== */
    typedef struct _node_s {
        T val;
        std::shared_ptr<struct _node_s> next;
    } node_s;

    typedef cpp_lib::linked_list<T>::node_s node_t;
    typedef std::shared_ptr<node_t> node_pointer_t;

  private:
    /* =================================================================== */
    /* Private Data Members */
    /* =================================================================== */

    node_pointer_t _head{};
    node_pointer_t _tail{};

    size_t _sz{};

    /**
     * @brief Generate new node
     * @param val
     * @return
     */
    node_pointer_t new_node(const T& val)
    {
        /* allocate new heap block */
        node_pointer_t n_node = std::make_shared<node_t>();

        /* fill out data */
        n_node.get()->next = NULL;
        n_node.get()->val = val;

        return n_node;
    }

  public:
    /* =================================================================== */
    /* Constructors/Destructors */
    /* =================================================================== */

    /**
     * @brief Default constructor
     */
    linked_list() : _head(NULL), _sz(0u)
    {
        std::cout << "Linked list constructed!" << std::endl;
    }

    /**
     * @brief Default destructor
     */
    ~linked_list()
    {
        std::cout << "Linked list destroyed!" << std::endl;
    }

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
        /**
         * @brief Default constructor
         * @param ptr
         */
        iterator() : _ptr(nullptr)
        {
            /* do nothing */
        }

        /**
         * @brief Custom constructor
         * @param ptr
         */
        iterator(node_pointer_t ptr) : _ptr(ptr)
        {
            /* do nothing */
        }

        /**
         * @brief Copy constructor
         * @param _node
         * @return
         */
        iterator& operator=(const node_pointer_t _node)
        {
            this->_ptr = _node;
            return *this;
        }

        /**
         * @brief Overload equality operator
         * @param itr
         * @return
         */
        bool operator!=(const iterator& itr)
        {
            return (this->_ptr != itr._ptr);
        }

        /**
         * @brief Overload dereference pointer
         * @return
         */
        T& operator*()
        {
            return _ptr->val;
        }

        /**
         * @brief pre-fix operator
         * @return
         */
        iterator& operator++()
        {
            /* increment pointer */
            if (_ptr) {
                _ptr = _ptr->next;
            }
            /* return new pointer */
            return *this;
        }

        /**
         * @brief post-fix increment
         * @param
         * @return
         */
        iterator operator++(int)
        {
            iterator& itr = *this;
            ++(*this);
            return itr;
        }
    };

    /**
     * @brief Constant iterator
     */
    class const_iterator: public iterator
    {
      public:
        using iterator::iterator;

        const T operator*() const
        {
            return this->_ptr.get()->val;
        }
    };

    /**
     * @brief Get the beginning of the list
     * @return
     */
    iterator begin()
    {
        return iterator(_head);
    }

    /**
     * @brief Get the end of the list
     * @return
     */
    iterator end()
    {
        return iterator(nullptr);
    }

    /**
     * @brief Get the beginning of the list
     * @return
     */
    const_iterator begin() const
    {
        return const_iterator(_head);
    }

    /**
     * @brief Get the end of the list
     * @return
     */
    const_iterator end() const
    {
        return const_iterator(nullptr);
    }

    /* =================================================================== */
    /* Operator overloads */
    /* =================================================================== */

    /**
     * @brief Overload the << operator to pretty print
     * @param os
     * @param obj
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os, const linked_list<T>& obj)
    {
        /* get the head pointer */
        cpp_lib::linked_list<T>::node_pointer_t traverse_ptr = obj._head;
        os << "HEAD --> ";
        /* traverse and print nodes */
        while (traverse_ptr != NULL) {
            os << traverse_ptr.get()->val << " --> ";
            traverse_ptr = traverse_ptr.get()->next;
        }
        os << "TAIL" << std::endl;
        return os;
    }

    /* =================================================================== */
    /* Public API */
    /* =================================================================== */

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
        }
    }
};

} // namespace cpp_lib