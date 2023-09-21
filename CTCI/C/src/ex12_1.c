/**
 * @brief
 * 3.1 Three in One: Describe how you could use a single array to implement three stacks
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "logging.h"

LOG_TAG(Stack3)

#define ARRAY_SZ 10u

typedef struct _stack3_s {
    uint8_t* data;
    struct {
        int32_t top;
        size_t base;
        size_t cap;
    } slot[3u];
    size_t sz;
} stack3_s;

static int32_t stack3_init(stack3_s* stack, size_t sz);
static int32_t stack3_push(stack3_s* stack, size_t slot, uint8_t val);
static int32_t stack3_pop(stack3_s* stack, size_t slot, uint8_t* val);
static void stack3_print(stack3_s* stack);

/**
 * @brief Init a stack so that it works like 3 stacks in one
 * @param stack
 * @param sz
 * @return
 */
static int32_t stack3_init(stack3_s* stack, size_t sz) {
    /* if stack pointer is invalid , return  */
    if (stack == NULL) {
        LOG_ERR("ERROR [%s] : Stack pointer invalid.", __func__);
        return -EINVAL;
    }

    if (sz == 0u || sz > 512u) {
        LOG_ERR("ERROR [%s] : Invalid stack size [0 < 512u].", __func__);
        return -ERANGE;
    }

    /* allocate memory for stack */
    stack->data = (uint8_t*) calloc(sizeof(uint8_t), sz);

    /* divide memory into requested partitions */
    stack->sz = sz;
    size_t partition_sz = sz / 3u;
    size_t offset_sz = sz % 3u;
    for (int i = 0; i < 3u; i++) {
        stack->slot[i].base = partition_sz * i;
        stack->slot[i].top = stack->slot[i].base - 1;
        stack->slot[i].cap = partition_sz * (i + 1);
        if (i == 2u) {
            stack->slot[i].cap += offset_sz;
        }
    }
    return 0;
}

static int32_t stack3_push(stack3_s* stack, size_t slot, uint8_t val) {
    /* if stack pointer is invalid , return  */
    if (stack == NULL) {
        LOG_ERR("ERROR [%s] : Stack pointer invalid.", __func__);
        return -EINVAL;
    }

    /* if there's space in the stack , push value */
    if (stack->slot[slot].top + 1 < (int32_t) (stack->slot[slot].cap)) {
        stack->data[++stack->slot[slot].top] = val;
    } else {
        LOG_ERR("ERROR [%s] : Stack is full.", __func__);
        return -EOF;
    }

    return 0;
}

static int32_t stack3_pop(stack3_s* stack, size_t slot, uint8_t* val) {
    /* if stack pointer is invalid , return  */
    if (stack == NULL) {
        LOG_ERR("ERROR [%s] : Stack pointer invalid.", __func__);
        return -EINVAL;
    }

    /* pop from the top */
    if (stack->slot[slot].top > (int32_t) (stack->slot[slot].base)) {
        *val = stack->data[stack->slot[slot].top--];
    } else {
        LOG_ERR("ERROR [%s] : Stack is empty.", __func__);
        return -EOF;
    }

    return 0;
}

static void stack3_print(stack3_s* stack) {
    LOG_INFO("====================================== ");
    for (int i = stack->sz - 1; i >= 0; i--) { LOG_INFO("[%2d] : %d", i, stack->data[i]); }
}

int main(int argc, char** argv) {
    stack3_s test = { 0u };

    stack3_init(&test, 15u);

    stack3_push(&test, 0u, 10u);
    stack3_push(&test, 0u, 10u);
    stack3_push(&test, 0u, 10u);
    stack3_push(&test, 0u, 10u);

    stack3_print(&test);

    stack3_push(&test, 1u, 20u);
    stack3_push(&test, 1u, 20u);
    stack3_push(&test, 1u, 20u);
    stack3_push(&test, 1u, 20u);
    uint8_t val = 0u;
    stack3_pop(&test, 1u, &val);
    stack3_push(&test, 1u, 99u);
    stack3_print(&test);

    stack3_push(&test, 2u, 30u);
    stack3_push(&test, 2u, 30u);
    stack3_push(&test, 2u, 30u);
    stack3_push(&test, 2u, 30u);
    stack3_print(&test);

    free(test.data);

    return 0;
}
