/**
 * @file stack.c
 *
 * @brief Stack Implementation
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#include "stack.h"

/**
 * @brief Pretty print a stack
 * @param in
 */
void stack_print(stack_s* in)
{
    /* if pointer is invalid, return */
    if (in == NULL) {
        printf("Error[%s]: Invalid stack pointer\n", __func__);
        return;
    }

    /* pretty print stack */
    for (int i = in->sz - 1u; i >= 0; i--) {
        printf("[%d] : %d", i, in->data[i]);
        if (i == in->top) {
            printf(" <- TOP \n");
        } else {
            printf("\n");
        }
    }

    /* if top is below stack then print that too */
    if (in->top == -1) {
        printf("[ ] : <- TOP\n");
    }
}

/**
 * @brief Check if stack is empty
 * @param stack
 * @return
 */
bool stack_empty(const stack_s* stack)
{
    if (stack == NULL) {
        printf("Error[%s]: Invalid stack pointer\n", __func__);
        return true;
    }

    /* check if stack is empty */
    return (stack->top == -1);
}

/**
 * @brief Push a value into stack
 * @param stack
 * @param val
 * @return
 */
int32_t stack_push(stack_s* stack, uint8_t val)
{
    /* if stack pointer invalid, return error */
    if (stack == NULL) {
        printf("Error[%s]: Invalid stack pointer\n", __func__);
        return -EINVAL;
    }

    /* if there's still space , add value */
    if (stack->top + 1u < stack->sz) {
        stack->top++;
        stack->data[stack->top] = val;
    } else {
        printf("Error[%s]: Stack is full\n", __func__);
        return -ERANGE;
    }

    return 0;
}

/**
 * @brief Peek the top value of the stack
 * @param stack
 * @param out
 * @return
 */
int32_t stack_peek(stack_s* stack, uint8_t* out)
{
    /* if stack pointer invalid, return error */
    if (stack == NULL) {
        printf("Error[%s]: Invalid stack pointer\n", __func__);
        return -EINVAL;
    }

    if (stack->top != -1) {
        *out = stack->data[stack->top];
    } else {
        return -ERANGE;
    }

    return 0;
}

/**
 * @brief Pop the top value of the stack
 * @param stack
 * @param out
 * @return
 */
int32_t stack_pop(stack_s* stack, uint8_t* out)
{
    /* if stack pointer invalid, return error */
    if (stack == NULL || out == NULL) {
        printf("Error[%s]: Invalid pointer\n", __func__);
        return -EINVAL;
    }

    /* if stack is empty return empty */
    if (stack->top == -1) {
        printf("Error[%s]: Stack is empty\n", __func__);
        return -ERANGE;
    }

    /* if output buffer set then copy value to buffer */
    *out = stack->data[stack->top];

    /* move top */
    stack->top--;

    return 0;
}

/**
 * @brief Initialize a new empty stack with given capacity
 * @param out
 * @param sz
 * @return
 */
int32_t stack_init(stack_s* out, size_t sz)
{
    /* if output pointer is invalid , return error */
    if (out == NULL) {
        printf("Error[%s]: Invalid stack pointer\n", __func__);
        return -EINVAL;
    }

    /* allocate memory for stack */
    out->data = (uint8_t*)calloc(sizeof(uint8_t), sz);
    out->sz = sz;
    out->top = -1;

    return 0;
}

/**
 * @brief De-initialize a stack on heap
 * @param in
 * @return
 */
int32_t stack_deinit(stack_s* in)
{
    /* if invalid stack pointer then return error code */
    if (in == NULL) {
        printf("Error[%s]: Invalid stack pointer\n", __func__);
        return -EINVAL;
    }

    /* free allocated memory blocks */
    if (in->data) {
        free(in->data);
        in->data = NULL;
    }

    /* de-init meta data */
    in->top = -1;
    in->sz = 0;

    return 0;
}

#ifdef __cplusplus
}
#endif