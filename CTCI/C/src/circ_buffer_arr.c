/**
 * @brief
 *
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#include "logging.h"

/*  1-->2-->3-->4-->5-->6   */

LOG_TAG(CIRCULAR_BUF);

typedef struct _circ_buf_s {
    uint8_t* data;
    size_t sz;
    size_t cap;
    int head;
    int tail;
} circ_buf_s;

/* definitions for static functions */
static int32_t circ_buf_init(circ_buf_s* buf, size_t sz);

static int32_t circ_buf_write_byte(circ_buf_s* buf, uint8_t val);

/**
 * @brief Initialize a circular buffer
 * @param buf
 * @param sz
 * @return
 */
static int32_t circ_buf_init(circ_buf_s* buf, size_t sz) {
    /* if pointers are invalid, return error */
    if (buf == NULL) {
        LOG_ERR("Buffer pointer invalid");
        return -EINVAL;
    }

    /* allocate memory for data */
    buf->data = (uint8_t*) calloc(sizeof(uint8_t), sz);
    buf->cap = sz;
    buf->sz = 0u;
    buf->head = -1;
    buf->tail = -1;

    return 0;
}

static int32_t circ_buf_write_byte(circ_buf_s* buf, uint8_t val) {
    /* pointer check */
    if (buf == NULL) {
        LOG_ERR("buffer pointer is invalid");
        return -EINVAL;
    }

    /* if first element then fix head and tail */
    if (buf->sz == 0u && buf->head == -1 && buf->tail == -1) {
        buf->head = 0u;
        buf->tail = 0u;
    } else {
        /* find out if we have space, if yes, then insert */
        size_t next = (buf->head + 1u) % buf->cap;
        if (next == buf->tail) {
            LOG_ERR("buffer is full");
            return -ENOSPC;
        }
        /* move head*/
        buf->head = next;
    }

    /* write data */
    buf->data[buf->head] = val;
    buf->sz++;

    return 0;
}

static int32_t circ_buf_read_byte(circ_buf_s* buf, uint8_t* byte) {
    /* pointer check */
    if (buf == NULL) {
        LOG_ERR("invalid buffer pointer");
        return -EINVAL;
    }

    /* if empty , just return */
    if (buf->sz == 0u || buf->head == -1 || buf->tail == -1) {
        LOG_ERR("buffer is empty");
        return -ENODATA;
    }

    /* read data  */
    if (byte) {
        *byte = buf->data[buf->tail];
    }

    /* move tail */
    size_t next = (buf->tail + 1u) % buf->cap;
    buf->tail = next;
    buf->sz--;

    return 0;
}

static void circ_buf_print(circ_buf_s* buf) {
    /* if pointers are invalid, return error */
    if (buf == NULL) {
        LOG_ERR("Buffer pointer invalid");
        return;
    }

    if (buf->data == NULL || buf->sz == 0u) {
        LOG_WARN("BUffer is empty");
        return;
    }

    LOG_INFO("============================================= ");

    for (size_t i = 0u; i < buf->cap; i++) {
        LOG_INFO("[%d] %d", i, buf->data[i]);
        if (i == buf->head) {
            LOG_INFO("^^^ HEAD");
        }
        if (i == buf->tail) {
            LOG_INFO("^^^ TAIL");
        }
    }
}

int main(int argc, char** argv) {
    LOG_INFO("Hello World.");

    circ_buf_s buf = { 0u };
    circ_buf_init(&buf, 10u);

    for (int i = 0; i < 10; i++) { circ_buf_write_byte(&buf, i); }

    circ_buf_read_byte(&buf, NULL);
    circ_buf_write_byte(&buf, 10u);

    circ_buf_print(&buf);

    free(buf.data);
}