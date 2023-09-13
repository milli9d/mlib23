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
#include "double_linked_list.hpp"

void linked_list_demo()
{
    cpp_lib::linked_list<uint32_t> list{};

    // list.push_front(30u);
    // list.push_front(20u);
    // list.push_front(10u);

    // list.push_back(40u);
    // list.push_back(50u);
    // list.push_back(60u);

    // for (auto& itr: list) {
    //     itr = itr / 10u;
    // }

    // std::cout << list;
}

void double_linked_list_demo()
{
    // cpp_lib::double_linked_list<uint32_t> list;
    // cpp_lib::double_linked_list<uint32_t>::iterator itr = list.begin();

    // list.push_front(10u);
    // list.push_front(10u);
    // list.push_front(10u);
    // list.push_front(10u);

    // std::cout << list << std::endl;
}

int main(int argc, char** argv)
{
    linked_list_demo();
    double_linked_list_demo();

    return 0u;
}