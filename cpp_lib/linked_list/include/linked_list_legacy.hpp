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
     * @brief node definition
     */
    typedef struct _node_s {
        struct _node_s* next;
        T val;
    } node_s;

  private:
    /* type defines */
    typedef node_s* node_pointer_t;
    typedef const node_pointer_t const_node_pointer_t;

  public:
    /* =================================================================== */
    /* Iterator definitions */
    /* =================================================================== */
    class iterator
    {
      public:
      private:
    };

    linked_list() {}
};

} // namespace cpp_lib