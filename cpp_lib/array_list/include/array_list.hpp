/**
 * @file array_list.hpp
 *
 * @brief Array List
 *
 */
#pragma once

#include <iostream>
#include <string>
#include <cstring>

namespace cpp_lib {

#define ARRAY_LIST_DEFAULT_CAP 10u

template<typename T>
class array_list
{
private:
    /* =================================================================== */
    /* Private data members */
    /* =================================================================== */

    /* private data members */
    T* _data {};
    size_t _sz {};
    size_t _cap {};

public:
    /* =================================================================== */
    /* Constructors/Destructors */
    /* =================================================================== */

    /**
     * @brief Default constructor
     */
    array_list()
    {
        /* allocate memory */
        _sz = 0u;
        _cap = ARRAY_LIST_DEFAULT_CAP;
        _data = new T[_cap];
        if (!_data) {
            throw std::bad_alloc();
        }
    }

    /**
     * @brief Custom constructor
     * @param sz
     */
    array_list(size_t sz)
    {
        /* sanity checks */
        if (sz == 0u) {
            std::__throw_range_error("Invalid input size");
        }

        /* infer default size */
        _sz = sz;
        _cap = (_sz <= ARRAY_LIST_DEFAULT_CAP) ? ARRAY_LIST_DEFAULT_CAP : _sz;

        /* allocate memory */
        _data = new T[_cap];
        if (!_data) {
            throw std::bad_alloc();
        }
    }

    ~array_list()
    {
        /* de-allocate memory */
        delete[] _data;
    }

    /* =================================================================== */
    /* Iterator overloads */
    /* =================================================================== */

    typedef T* iterator;
    typedef const T* const_iterator;

    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef const std::reverse_iterator<iterator> const_reverse_iterator;

    iterator begin()
    {
        return &_data[0u];
    }

    iterator end()
    {
        return &_data[_sz];
    }

    /* =================================================================== */
    /* Operator overloads */
    /* =================================================================== */

    /**
     * @brief Overload << operator for printing
     * @param os
     * @param obj
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os, const array_list<T>& obj)
    {
        for (size_t i = 0; i < obj._sz; i++) {
            os << " arr[" << i << "] => " << obj._data[i] << std::endl;
        }
        return os;
    }

    /**
     * @brief Overload the [] operator
     * @param idx
     * @return
     */
    constexpr T& operator[](size_t idx)
    {
        /* sanity checks */
        if (idx >= _sz) {
            throw std::out_of_range("IDX out of range");
        }
        return _data[idx];
    }

    /* =================================================================== */
    /* Operator overloads */
    /* =================================================================== */

    /**
     * @brief
     * @param new_cap
     */
    void reserve(size_t new_cap)
    {
        /* sanity check */
        if (new_cap == 0u || new_cap < _sz) {
            throw std::invalid_argument("new capacity invalid value");
        }

        /* extend allocated memory */
        T* new_mem = new T[new_cap];
        if (!new_mem) {
            throw std::bad_alloc();
        }

        /* copy over data */
        std::fill(begin(), end(), T {});
        for (size_t i = 0; i < _sz; i++) {
            new_mem[i] = _data[i];
        }

        delete[] _data;

        /* update meta-data */
        _data = new_mem;
        _cap = new_cap;
    }

    /**
     * @brief
     * @param new_cap
     */
    void resize(size_t new_cap)
    {
        /* reserve memory and update size */
        reserve(new_cap);
        _sz = new_cap;
    }

    /**
     * @brief Push back to the last element
     */
    void push_back(const T& val)
    {
        /* resize if needed */
        if (_sz == _cap) {
            resize(_cap * 2u);
        }

        /* emplace data */
        _data[_sz++] = val;
    }
};

} // namespace cpp_lib