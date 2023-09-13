#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

/* linked list definition */
typedef struct _node_s {
    uint8_t val;
    struct _node_s* next;
} node_s;

/* declarations */
static node_s* _new_node(const uint8_t val, const node_s* next);
static int32_t push_front(node_s** head, const uint8_t val);
static int32_t print_list(const node_s* list);
static int32_t dealloc_list(node_s** head);
static int32_t reverse_list(node_s** head);
static int32_t remove_dups(node_s** head);

/**
 * Allocate a new node
 */
static node_s* _new_node(const uint8_t val, const node_s* next)
{
    node_s* node = (node_s*)malloc(sizeof(node_s));
    node->next = (node_s*)next;
    node->val = val;

    return node;
}

/**
 * Push to the front of the list
 */
int32_t push_front(node_s** head, const uint8_t val)
{
    /* if head pointer is invalid , return error */
    if (head == NULL) {
        printf("Error: Invalid list.\n");
        return -EINVAL;
    }

    /* if head is NULL , replace head */
    if (*head == NULL) {
        *head = _new_node(val, NULL);
    } else {
        /* if head is not null store head as next and replace head */
        node_s* old_head = *head;
        *head = _new_node(val, old_head);
    }

    return 0;
}

/**
 * Pretty print a list
 */
int32_t print_list(const node_s* list)
{
    /* if list is empty return error */
    if (list == NULL) {
        printf("Empty list.\n");
        return -ENODATA;
    }

    /* iterate through list and print elements */
    node_s* ptr = (node_s*)list;
    printf("HEAD -> ");

    while (ptr != NULL) {
        printf("%d -> ", ptr->val);
        ptr = ptr->next;
    }
    printf("TAIL\n");

    return 0;
}

/**
 * De-allocate heap memory
 */
int32_t dealloc_list(node_s** head)
{
    /* list is already invalidated */
    if (head == NULL) {
        return -ENODATA;
    }

    /* list already empty */
    if (*head == NULL) {
        return 0;
    }

    /* traverse and free each block */
    node_s* ptr = *head;
    while (ptr != NULL) {
        node_s* next = ptr->next;

        /* free this node */
        ptr->next = NULL;
        free(ptr);

        /* move to next node */
        ptr = next;
    }

    return 0;
}

/**
 * Remove duplicates from list
 */
int32_t remove_dups(node_s** head)
{
    /* sanity checks */
    if (head == NULL) {
        return -EINVAL;
    }

    if (*head == NULL) {
        return -ENODATA;
    }

    /* make a hash map */
    bool map[256u] = { 0u };

    /* traverse and mark duplicates */
    node_s* curr = *head;
    node_s* prev = NULL;

    while (curr != NULL) {
        /* see if curr is already seen */
        if (map[curr->val] == true) {
            /* remember next node */
            node_s* next = curr->next;

            /* delete this node */
            free(curr);

            /* we can do this safely because prev is never head */
            if (prev) {
                prev->next = next;
            }

            /* next node becomes current , prev node remains the same */
            curr = next;

        } else {
            /* mark as seen */
            map[curr->val] = true;
            prev = curr;
            curr = curr->next;
        }
    }

    return 0;
}

/**
 * @brief Reverse a linked list
 * @param head
 * @return
 */
int32_t reverse_list(node_s** head)
{
    /* if list pointer is invalid , return error */
    if (head == NULL) {
        return -ENODATA;
    }

    /* if list is empty , return OK */
    if (*head == NULL) {
        return 0;
    }

    /* maintain 2 consecutive pointers */
    node_s* curr = *head;
    node_s* prev = NULL;

    while (curr != NULL) {
        /* store for later */
        node_s* next = curr->next;

        /* reverse this link */
        curr->next = prev;

        /* traverse */
        prev = curr;
        curr = next;
    }

    /* fix head */
    *head = prev;

    return 0;
}

int main(int argc, char** argv)
{
    /* test 1 */
    {
        node_s* list = NULL;

        for (int i = 0; i < 15; i++) {
            push_front(&list, i * 10);
            push_front(&list, i * 10);
        }

        (void)print_list(list);

        (void)remove_dups(&list);
        (void)print_list(list);

        (void)reverse_list(&list);
        (void)print_list(list);

        (void)dealloc_list(&list);
    }

    /* test 2 */
    {
        node_s* list = NULL;

        push_front(&list, 10);

        (void)remove_dups(&list);

        (void)print_list(list);

        (void)dealloc_list(&list);
    }

    return 0;
}