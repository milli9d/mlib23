/**
 * @brief Design an LRU Cache
 *
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "logging.h"

LOG_TAG(LRU_CACHE);

#define HASH_TABLE_SZ 100u

/* ============================================================ */
/* Double Ended Linked List Queue API */
/* ============================================================ */

/**
 * We need
 * 1. Insert to tail
 * 2. Pop from front
 * 3. Delete from middle if node given
 *
 */
typedef struct _node_s {
    struct _node_s* next;
    struct _node_s* prev;
    uint8_t val;
} node_s;

typedef struct _queue_s {
    node_s* head;
    node_s* tail;
} queue_s;

static node_s* new_node(uint8_t val) {
    node_s* out = (node_s*) calloc(sizeof(node_s), 1u);
    out->next = NULL;
    out->prev = NULL;
    out->val = val;
    return out;
}

static node_s* enqueue(queue_s* q, uint8_t val) {
    if (q == NULL) {
        return NULL;
    }

    /* if head is invalid , replace head */
    if (q->head == NULL) {
        q->head = new_node(val);
        return q->head;
    }

    /* push back , check if tail is valid */
    if (!q->tail) {
        node_s* ptr = q->head;
        while (ptr != NULL && ptr->next != NULL) { ptr = ptr->next; }
        q->tail = ptr;
    }

    /* tail is valid , push new node */
    node_s* insert = new_node(val);

    q->tail->next = insert;
    insert->prev = q->tail;

    q->tail = insert;

    return q->tail;
}

static node_s* dequeue(queue_s* q, uint8_t* out) {
    if (q == NULL) {
        return NULL;
    }

    if (q->head == NULL) {
        return NULL;
    }

    /* head is valid, pop head */
    if (out) {
        *out = q->head->val;
    }

    node_s* to_del = q->head;

    q->head = q->head->next;
    q->head->prev = NULL;

    free(to_del);
    to_del = NULL;

    return q->head;
}

static void queue_print(queue_s* q) {
    if (q == NULL || q->head == NULL) {
        return;
    }

    node_s* ptr = q->head;
    while (ptr) {
        LOG_INFO("%d ^^^", ptr->val);
        ptr = ptr->next;
    }
}

/* ============================================================ */
/* HashMap API */
/* ============================================================ */

/* private declarations */
node_s* map[HASH_TABLE_SZ] = { NULL };

static int32_t hash_set_insert(int16_t key, node_s* val) {
    map[key % HASH_TABLE_SZ] = val;
    return 0;
}

static int32_t hash_set_get(int16_t key, node_s** out) {
    if (out) {
        *out = map[key % HASH_TABLE_SZ];
        if (*out == NULL) {
            return -ENODATA;
        }
    }

    return 0;
}

/* ============================================================ */
/* LRU Cache API */
/* ============================================================ */

// static void get(uint16_t key, uint16_t* val);
// static void put(uint16_t key, uint16_t val);

/* ============================================================ */
/* LRU Cache Main */
/* ============================================================ */

int main(int argc, char** argv) {
    queue_s q = { 0u };

    node_s* ptr = enqueue(&q, 10u);
    ptr = enqueue(&q, 20u);
    ptr = enqueue(&q, 30u);
    hash_set_insert(0u, ptr);
    ptr = enqueue(&q, 40u);

    dequeue(&q, NULL);

    hash_set_get(0u, &ptr);

    LOG_INFO("%d", ptr->val);

    queue_print(&q);

    LOG_INFO("done");

    return 0;
}