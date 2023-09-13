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
    /* ===================================================================== */
    /* Iterator API */
    /* ===================================================================== */
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

    /* ===================================================================== */
    /* Rule of three */
    /* ===================================================================== */

    /**
     * @brief
     */
    linked_list() : _sz(0u), _head(nullptr) {}

    /**
     * @brief
     */
    linked_list(size_t sz) : _sz(sz), _head(nullptr)
    {
        for (size_t i = 0; i < _sz; i++) {}
    }
};

} // namespace cpp_lib