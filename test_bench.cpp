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

#include "stack.h"

int main(int argc, char** argv)
{
    stack_s stack = { 0u };

    stack_init(&stack, 10u);

    uint8_t val = 0u;
    stack_pop(&stack, &val);

    stack_push(&stack, 10u);
    stack_push(&stack, 20u);
    stack_push(&stack, 30u);
    stack_push(&stack, 10u);
    stack_push(&stack, 20u);
    stack_push(&stack, 30u);
    stack_push(&stack, 10u);
    stack_push(&stack, 20u);
    stack_push(&stack, 30u);
    stack_push(&stack, 10u);
    stack_push(&stack, 10u);

    val = 0u;
    stack_pop(&stack, &val);
    stack_pop(&stack, &val);
    stack_pop(&stack, &val);
    stack_pop(&stack, &val);
    stack_pop(&stack, &val);
    stack_pop(&stack, &val);
    stack_pop(&stack, &val);

    printf("VAL = %d\n", val);

    stack_print(&stack);

    stack_deinit(&stack);

    return 0;
}