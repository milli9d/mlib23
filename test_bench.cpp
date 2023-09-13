/**
 * @brief Generic Test Bench to experiment and learn with components
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string>

#include <vector>

#include "linked_list.h"

int main(int argc, char** argv)
{
    std::vector<uint8_t> arr;
    arr.resize(10u);

    std::vector<uint8_t>::iterator itr = arr.begin();
    *itr = 10u;

    node_s* list = NULL;

    push_front(50u, &list);
    push_front(40u, &list);
    push_front(30u, &list);
    push_front(20u, &list);
    push_front(10u, &list);

    print_list(list);

    return 0;
}