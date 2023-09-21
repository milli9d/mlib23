/**
 * @brief Queue implementation
 *
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

#include "logging.h"

LOG_TAG(QUEUE);

typedef struct _queue_s {
    uint8_t* data;
    size_t sz;
    int head;
    int tail;
} queue_s;

static int32_t queue_init(queue_s* queue, size_t sz);

/**
 * @brief Pretty print the queue
 * @param queue
 */
static void queue_print(const queue_s* queue) {
    /* if queue pointer empty , return empty list  */
    if (queue == NULL || queue->data == NULL || queue->sz == 0u) {
        LOG_ERR("%s : Queue is empty.\n", __func__);
    }

    /*  */
    for (int i = 0; i < queue->sz; i++) { LOG_INFO("%d ", queue->data[i]); }

    printf("\n");
}

/**
 * @brief Initialize the queue
 * @param queue
 * @param sz
 * @return
 */
static int32_t queue_init(queue_s* queue, size_t sz) {
    /* if queue is invalid , return error */
    if (queue == NULL) {
        LOG_ERR("%s : Error queue invalid\n", __func__);
        return -EINVAL;
    }

    /* allocate memory for queue */
    queue->data = (uint8_t*) calloc(sizeof(uint8_t), sz);
    queue->sz = sz;
    queue->head = -1;
    queue->tail = -1;

    return 0;
}

/**
 * @brief Enqueue an element
 * @param queue
 * @param val
 * @return
 */
static int32_t enqueue(queue_s* queue, uint8_t val) {
    /* if queue is empty  */
    if (queue == NULL || queue->data == NULL || queue->sz == 0u) {
        printf("Error [%s] : Queue pointer invalid.\n", __func__);
        return -EINVAL;
    }

    /* get the next tail element */
    int tail_next = (queue->tail + 1u) % queue->sz;

    /* check if queue is full */
    if (tail_next == queue->head) {
        printf("Error [%s] : Queue is full. Cannot insert %d.\n", __func__, val);
        return -ERANGE;
    }

    /* if first element, then update head */
    if (queue->tail == -1) {
        queue->head = 0;
        queue->tail = 0;
    } else {
        /* if not , then update tail */
        queue->tail = tail_next;
    }

    /* insert element */
    queue->data[queue->tail] = val;

    return 0;
}

/**
 * @brief Dequeue an element
 * @param queue
 * @param val
 * @return
 */
static int32_t dequeue(queue_s* queue, uint8_t* val) {
    /* if queue is empty  */
    if (queue == NULL || queue->data == NULL || queue->sz == 0u) {
        LOG_ERR("Queue pointer invalid.");
        return -EINVAL;
    }

    /* check if list is empty */
    if (queue->tail == -1) {
        LOG_ERR("Queue is empty.");
        return -ERANGE;
    }

    int next_head = (queue->head + 1u) % queue->sz;

    /* if output needed, supply */
    if (val) {
        *val = queue->data[queue->head];
    }

    /* delete element data */
    queue->data[queue->head] = 0u;

    /* if first element then reset queue */
    if (queue->head == queue->tail) {
        queue->head = -1;
        queue->tail = -1;
    } else {
        queue->head = next_head;
    }

    return 0;
}

int main(int argc, char** argv) {
    LOG_INFO("Queue Test");
    queue_s new_q = { 0u };

    queue_init(&new_q, 10u);

    enqueue(&new_q, 10u);
    enqueue(&new_q, 20u);
    enqueue(&new_q, 30u);
    enqueue(&new_q, 50u);

    dequeue(&new_q, NULL);
    dequeue(&new_q, NULL);
    dequeue(&new_q, NULL);
    dequeue(&new_q, NULL);
    dequeue(&new_q, NULL);

    queue_print(&new_q);

    free(new_q.data);

    return 0;
}