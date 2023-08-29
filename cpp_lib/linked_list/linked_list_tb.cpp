/**
 * @file linked_list_tb.cpp
 *
 * @brief Array List Test Bench
 *
 */

#include <stdio.h>
#include <stdint.h>

#include <vector>

#include "linked_list.hpp"

void linked_list_demo()
{
    cpp_lib::linked_list<uint32_t> list;

    list.push_front(30u);
    list.push_front(20u);
    list.push_front(10u);

    list.push_back(40u);
    list.push_back(50u);
    list.push_back(60u);

    for (auto& itr: list) {
        itr = itr / 2u;
    }

    std::cout << list;
}

int main(int argc, char** argv)
{
    linked_list_demo();

    return 0u;
}