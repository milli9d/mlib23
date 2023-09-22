/**
 * @file queue.c
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

#include "queue.h"

int32_t queue_init(queue_s* q_in, size_t sz)
{
    /* if q_in pointer invalid , report error */
    if (q_in == NULL) {
        printf("Error[%s] : Invalid pointer\n", __func__);
        return -EINVAL;
    }

    /* if sz is invalid , report error */
    if (sz == 0u) {
        printf("Error[%s] : Size is zero.\n", __func__);
        return -ERANGE;
    }

    q_in->data = (uint8_t*)calloc(sizeof(uint8_t), sz);
    q_in->sz = sz;

    return 0;
}

#ifdef __cplusplus
}
#endif