/**
 * @file stack.c
 *
 * @brief Stack Implementation
 *
 */
#ifndef __C_LIB_STACK_H_
#define __C_LIB_STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

typedef struct _stack_s {
    uint8_t* data;
    int32_t top;
    size_t sz;
} stack_s;

/**
 * @brief Initialize a new empty stack with given capacity
 * @param out
 * @param sz
 * @return
 */
int32_t stack_init(stack_s* out, size_t sz);

/**
 * @brief Pretty print a stack
 * @param in
 */
void stack_print(stack_s* in);

/**
 * @brief Push a value into stack
 * @param stack
 * @param val
 * @return
 */
int32_t stack_push(stack_s* stack, uint8_t val);

/**
 * @brief Peek the top value of the stack
 * @param stack 
 * @param out 
 * @return 
 */
int32_t stack_peek(stack_s* stack, uint8_t* out);

/**
 * @brief Pop the top value of the stack
 * @param stack 
 * @param out 
 * @return 
 */
int32_t stack_pop(stack_s* stack, uint8_t* out);

#ifdef __cplusplus
}
#endif /* extern "C" */
#endif /* __C_LIB_STACK_H_ */
