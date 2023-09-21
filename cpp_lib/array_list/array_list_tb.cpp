/**
 * @file array_list_tb.cpp
 *
 * @brief Array List Test Bench
 *
 */

#include <stdio.h>
#include <stdint.h>

#include <vector>

#include "array_list.hpp"

void array_list_demo() {
    cpp_lib::array_list<uint32_t> new_arr_list;

    new_arr_list.reserve(100u);

    new_arr_list.resize(10u);
    std::cout << new_arr_list;

    new_arr_list.push_back(10u);

    std::cout << new_arr_list;
}

int main(int argc, char** argv) {
    array_list_demo();

    return 0u;
}