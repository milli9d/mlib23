/**
 * @file linked_list.c
 *
 * @brief Array List Test Bench
 *
 */
#include <stdio.h>
#include <stdint.h>

typedef struct _node_s {
    uint64_t val;
    struct _node_s* next;
} node_s;

/**
 * @brief Push to front of list
 * @param val
 * @return
 */
int32_t push_front(uint64_t val, node_s** head);

/**
 * @brief Pretty print list
 * @param head
 * @return
 */
int32_t print_list(const node_s* head);