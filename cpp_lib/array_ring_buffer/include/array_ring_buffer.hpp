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

/**
 * TODO:
 * 1. Ring Buffer insert
 * 2. Ring Buffer size
 *
 */

namespace cpp_lib {

template<typename T, size_t S>
class array_ring_buffer {
  private:
    /* meta ring buffer */
    typedef T* pointer_t;
    typedef const pointer_t const_pointer_t;

    pointer_t _data{};

    size_t _sz = 0u;
    size_t _head{};
    size_t _tail{};

  public:
    /* ===================================================================== */
    /* Rule of 5 */
    /* ===================================================================== */

    /**
     * @brief Default constructor
     */
    array_ring_buffer() : _sz(S) {
        /* allocate buffer */
        _data = (T*) calloc(S, sizeof(T));
    }

    /**
     *
     * @brief Destructor
     */
    ~array_ring_buffer() {
        /* deallocate memory */
        free(_data);
    }

    /* ===================================================================== */
    /* Operator overloads */
    /* ===================================================================== */

    /**
     * @brief Overload the << operator
     * @param os
     * @param obj
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os, const array_ring_buffer<T, S>& obj) {
        /* pretty print to output stream */
        for (size_t i = 0u; i < obj._sz; i++) {
            os << obj._data[i];
            if (i == obj._tail) {
                os << "{T}";
            }
            if (i == obj._head) {
                os << "{H}";
            }
            os << " -> ";
        }
        os << std::endl;

        return os;
    }

    /* ===================================================================== */
    /* Public API */
    /* ===================================================================== */
};

} // namespace cpp_lib