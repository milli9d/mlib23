/**
 * @file linked_list_tb.cpp
 *
 * @brief Array List Test Bench
 *
 */

#include <stdio.h>
#include <stdint.h>

#include <vector>

#include "array_ring_buffer.hpp"

/**
 * @brief
 */
void _demo(void) {
    cpp_lib::array_ring_buffer<uint16_t, 10u> arr;

    std::cout << arr;
}

int main(int argc, char** argv) {
    _demo();
    return 0u;
}