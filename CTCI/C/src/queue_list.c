/**
 * @brief
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "logging.h"
LOG_TAG(QUEUE_LIST);

// FIFO Buffer - Push back, pop front

typedef struct _node_s {
    struct _node_s* next;
    uint8_t val;
} node_s;

typedef struct _queue_s {
    node_s* head;
    node_s* tail;
} queue_s;

static void queue_print(queue_s* q) {
    if (q->head == NULL) {
        LOG_ERR("Queue is empty");
        return;
    }

    node_s* ptr = q->head;
    while (ptr != NULL) {
        LOG_INFO("%d ^^^", ptr->val);
        ptr = ptr->next;
    }
}

static node_s* new_node(uint8_t val) {
    node_s* out = (node_s*) calloc(sizeof(node_s), 1u);
    out->val = val;
    out->next = NULL;
    return out;
}

static void enqueue(queue_s* q, uint8_t val) {
    /* Push Back */

    /* pointer check */
    if (q == NULL) {
        LOG_ERR("Queue pointer invalid");
        return;
    }

    /* if head is null, replace head */
    if (q->head == NULL) {
        q->head = new_node(val);
        q->tail = q->head;
        return;
    }

    if (q->tail == NULL) {
        /* find tail */
        node_s* ptr = q->head;
        while (ptr != NULL && ptr->next != NULL) { ptr = ptr->next; }
        q->tail = ptr;
    }

    /* push to tail and update tail */
    q->tail->next = new_node(val);
    q->tail = q->tail->next;

    return;
}

static void dequeue(queue_s* q, uint8_t* out) {
    /* POP front */
    if (q == NULL) {
        LOG_ERR("invalid list pointer");
        return;
    }

    if (q->head == NULL) {
        LOG_ERR("queue is empty");
        return;
    }

    /* if not empty , pop front */
    if (out) {
        *out = q->head->val;
    }

    /* deallocate */
    node_s* to_del = q->head;
    q->head = q->head->next;
    free(to_del);
    to_del = NULL;
}

int main(int argc, char** argv) {
    queue_s queue = { 0u };

    enqueue(&queue, 10u);
    enqueue(&queue, 20u);
    enqueue(&queue, 30u);
    enqueue(&queue, 40u);

    dequeue(&queue, NULL);
    dequeue(&queue, NULL);
    dequeue(&queue, NULL);

    queue_print(&queue);

    return 0;
}