/**
 * @file static_array_tb.cpp
 *
 * @brief Static array Test Bench
 *
 */

#include <iostream>
#include <array>

#include "static_array.hpp"

void static_array_demo()
{
    /* allocate test arrays */
    cpp_lib::static_array<uint32_t, 5u> num_arr {};
    cpp_lib::static_array<uint32_t, 5u> num_arr2 {};

    num_arr[2u] = 10u;

    /* print array */
    std::cout << num_arr;
    std::cout << num_arr2;
    std::cout << ((num_arr == num_arr2) ? "True" : "False") << std::endl;

    for (auto i: num_arr) {
        std::cout << i << std::endl;
    }
}

int main(int argc, char** argv)
{
    static_array_demo();

    return 0u;
}