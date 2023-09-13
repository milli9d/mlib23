/**
 * @file double_linked_list.cpp
 *
 * @brief Double linked list template class
 *
 * Double linked list implementation
 *
 */
#pragma once

#include <cstring>
#include <iostream>
#include <memory>

namespace cpp_lib {

/**
 * @brief
 * @tparam T
 */
template<typename T>
class double_linked_list
{
  public:
    /**
     * @brief Double linked list node type
     */
    typedef struct node_s {
        T val;
        std::shared_ptr<struct node_s> next;
        std::shared_ptr<struct node_s> prev;
    } node_t;

  private:
    /* type define helpers */
    typedef std::shared_ptr<node_t> node_pointer_t;
    typedef const node_pointer_t const_node_pointer_t;

    /* private data members */
    node_pointer_t _head{};
    node_pointer_t _tail{};
    size_t _sz{};

    node_pointer_t new_node(const T& val)
    {
        node_pointer_t ptr = std::make_shared<node_t>();

        ptr.get()->val = val;
        ptr.get()->next = NULL;
        ptr.get()->prev = NULL;

        return ptr;
    }

  public:
    class iterator
    {
      private:
        /* node pointer */
        node_pointer_t _ptr = nullptr;

      public:
        /* constructora */
        iterator() : _ptr(nullptr) {}
        iterator(const node_pointer_t& ptr) : _ptr(ptr) {}

        /* ======================================================== */
        /* overloads */
        /* ======================================================== */

        /**
         * @brief Overload the stream output operator
         * @param os
         * @param obj
         * @return
         */
        friend std::ostream& operator<<(std::ostream& os, const iterator& obj)
        {
            /* pretty print output stream */
            os << obj._ptr << std::endl;
            return os;
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
         * @brief Overload the inequality operator
         * @param obj1
         * @param obj2
         * @return
         */
        friend bool operator!=(iterator& obj1, iterator& obj2)
        {
            return obj1._ptr == obj2._ptr;
        }

        /**
         * @brief Pre-fix increment operator
         * @param obj
         * @return
         */
        iterator& operator++()
        {
            if (_ptr) {
                _ptr = _ptr->next;
            }
            return *this;
        }

        /**
         * @brief Post-fix increment operator
         * @return
         */
        iterator& operator++(int)
        {
            iterator& itr = *this;
            ++(*this);
            return itr;
        }

        /**
         * @brief De-reference operator
         * @return
         */
        constexpr T& operator*()
        {
            return _ptr->val;
        }
    };

    /**
     * @brief Iterator to beginning of list
     * @return
     */
    iterator begin()
    {
        return iterator(_head);
    }

    /**
     * @brief Iterator to end of list
     * @return
     */
    iterator end()
    {
        return iterator(nullptr);
    }

  public:
    /* ========================================================================= */
    /* Rule of 3 */
    /* ========================================================================= */

    /* default constructor */
    double_linked_list() {}

    /* ========================================================================= */
    /* Oepartor overload */
    /* ========================================================================= */

    /**
     * @brief
     * @param os
     * @param obj
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os, const double_linked_list<T>& obj)
    {
        /*  */
        os << "[HEAD] <-->";
        for (const auto itr: obj) {
            os << itr << "<-->";
        }
        os << "[TAIL]";
        return os;
    }

    /* ========================================================================= */
    /* Public API */
    /* ========================================================================= */

    /**
     * @brief Push to the front of the list
     * @param val
     */
    void push_front(const T& val)
    {
        /* allocate new node */
        node_pointer_t n_node = new_node(val);
        _sz++;

        /* if not empty, attach rest of list */
        if (_head != NULL) {
            n_node->next = _head;
        }

        /* if list is empty, replace _head/_tail */
        if (_head == nullptr) {
            _tail = n_node;
        }

        _head = n_node;
        return;
    }
};

} // namespace cpp_lib