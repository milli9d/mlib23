/**
 * @file linked_list.c
 *
 * @brief Array List Test Bench
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

#include "linked_list.h"

/**
 * @brief Allocate new node
 * @return
 */
static node_s* new_node(uint64_t val)
{
    /* allocate new node */
    node_s* ptr = (node_s*)calloc(sizeof(node_s), 1u);

    ptr->next = NULL;
    ptr->val = val;

    return ptr;
}

/**
 * @brief
 * @param head
 * @return
 */
size_t list_size(const node_s* head)
{
    if (head == NULL) {
        return 0;
    }

    /* count nunber of nodes */
    size_t out = 0u;
    const node_s* ptr = head;
    while (ptr != NULL) {
        ptr = ptr->next;
        out++;
    }

    return out;
}

/**
 * @brief
 * @param val
 * @param head
 * @return
 */
int32_t push_back(uint64_t val, node_s** head)
{
    /* if list pointer is invalid , return error */
    if (head == NULL) {
        return -EINVAL;
    }

    /* corner case 1: list in empty */
    if (*head == NULL) {
        *head = new_node(val);
        return 0;
    }

    /* go to node before last node */
    node_s* ptr = *head;
    while (ptr != NULL && ptr->next != NULL) {
        ptr = ptr->next;
    }

    /* now ptr is at last node */

    return 0;
}

/**
 * @brief Push to front of list
 * @param val
 * @return
 */
int32_t push_front(uint64_t val, node_s** head)
{
    /* check if linked list pointer is invalid */
    if (head == NULL) {
        return -EINVAL;
    }

    /* allocate new node */
    node_s* node = new_node(val);

    /* if head is not NULL then add rest of list to node */
    if (*head != NULL) {
        node->next = *head;
    }

    /* add node to *head */
    *head = node;
    return 0;
}

/**
 * @brief Reverse the linked list
 * @return
 */
int32_t reverse_list()
{
    return 0;
}

/**
 * @brief Pretty print list
 * @param head
 * @return
 */
int32_t print_list(const node_s* head)
{
    /* if list pointer is invalid , return */
    if (head == NULL) {
        return -ENODATA;
    }

    /* pretty print list */
    printf("\n\e[1;95m[SIZE] = %ld \e[1;92m[HEAD] -> \e[0m", list_size(head));
    const node_s* ptr = head;
    while (ptr != NULL) {
        printf("[%ld] -> ", ptr->val);
        ptr = ptr->next;
    }
    printf("\e[1;92m[TAIL]\e[0m\n\n");

    return 0;
}

/* ========================================================================= */
/* ========================================================================= */

/**
 * @brief test bench main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv)
{
    node_s* list = new_node(10u);

    push_front(20u, &list);
    push_front(30u, &list);
    push_front(40u, &list);

    print_list(NULL);
    print_list(list);

    return 0;
}

#ifdef __cplusplus
}
#endif