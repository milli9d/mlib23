/**
 * @file static_array.hpp
 *
 * @brief Array List
 *
 */
#pragma once

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>

namespace cpp_lib {
template<typename T, size_t S>
class static_array
{
private:
    /* =================================================================== */
    /* Private data members */
    /* =================================================================== */

    /* allocate static array for data-type */
    T _data[S] {};
    size_t _sz = S;

public:
    /* =================================================================== */
    /* Constructors/Destructors */
    /* =================================================================== */

    /**
     * @brief Default constructor
     */
    static_array()
    {
        /* perform checks on data type and sizes */
        if (_sz == 0u || sizeof(T) == 0u) {
            std::__throw_length_error("Array has invalid length.");
        }
    }

    /**
     * @brief Default destructor
     */
    ~static_array()
    {
        /* clear array; secure erase */
        memset((uint8_t*)_data, 0u, sizeof(T) * _sz);
    }

    /* =================================================================== */
    /* Iterators */
    /* =================================================================== */

    /* iterator defines*/
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef const std::reverse_iterator<iterator> const_reverse_iterator;

    typedef T& reference;
    typedef const T& const_reference;

    /**
     * @brief Get begin iterator
     * @return
     */
    constexpr iterator begin()
    {
        return &_data[0u];
    }

    /**
     * @brief Get end iterator
     * @return
     */
    constexpr iterator end()
    {
        return &_data[_sz];
    }

    /**
     * @brief Get begin reverse iterator
     * @return
     */
    constexpr reverse_iterator rbegin()
    {
        return std::reverse_iterator(end());
    }

    /**
     * @brief Get end reverse iterator
     * @return
     */
    constexpr reverse_iterator rend()
    {
        return std::reverse_iterator(begin());
    }

    /* =================================================================== */
    /* Operator Overloads API */
    /* =================================================================== */

    /**
     * @brief Overload [] operator
     * @param idx
     * @return
     */
    constexpr T& operator[](size_t idx)
    {
        /* sanity check */
        if (idx >= _sz) {
            std::__throw_out_of_range_fmt("Out of array range. Size = %ld",
                _sz);
        }
        return _data[idx];
    }

    /**
     * @brief Overload equality operator
     * @param obj
     * @return
     */
    bool operator==(const static_array<T, S>& obj)
    {
        /* if length is not equal , arrays are not equal */
        if (_sz != obj._sz) {
            return false;
        }

        /* compare each element */
        for (int i = 0; i < _sz; i++) {
            if (_data[i] != obj._data[i]) {
                return false;
            }
        }

        return true;
    }

    /**
     * @brief Overload << operator
     * @param os
     * @param obj
     * @return
     */
    constexpr friend std::ostream& operator<<(std::ostream& os,
        const static_array<T, S>& obj)
    {
        /* sanity checks */
        if (obj._sz == 0u) {
            std::__throw_invalid_argument("Invalid array size");
        }

        if (obj._data == NULL) {
            std::__throw_invalid_argument("Invalid array data.");
        }

        /* print data to ostream */
        for (int i = 0; i < obj._sz; i++) {
            os << "arr[" << i << "] => " << obj._data[i] << std::endl;
        }
        return os;
    }

    /* =================================================================== */
    /* Public API */
    /* =================================================================== */

    /**
     * @brief Get reference to element at idx
     * @param idx
     * @return
     */
    constexpr T& at(size_t idx)
    {
        /* sanity check */
        if (idx >= _sz) {
            std::__throw_out_of_range_fmt("Out of array range. Size = %ld",
                _sz);
        }
        return _data[idx];
    }

    /**
     * @brief Fill the array with a constant value
     * @param val
     */
    constexpr void fill(const T& val)
    {
        /* iterate and fill all elements */
        for (T& i: _data) {
            i = val;
        }
    }

    /**
     * @brief Get the front element of the array
     * @param
     * @return
     */
    constexpr T& front(void)
    {
        return _data[0u];
    }

    /**
     * @brief Get the last element of the array
     * @param
     * @return
     */
    constexpr T& back(void)
    {
        return _data[_sz - 1u];
    }

    /**
     * @brief Get const data pointer
     * @param
     * @return
     */
    constexpr const T* data(void) const
    {
        return _data;
    }

    /**
     * @brief Get data pointer
     * @param
     * @return
     */
    constexpr T* data(void)
    {
        return _data;
    }
};

} // namespace cpp_lib