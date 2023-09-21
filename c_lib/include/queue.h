/**
 * @file queue.c
 *
 * @brief Stack Implementation
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _queue_s {
    uint8_t* data;
    size_t head;
    size_t tail;
    size_t sz;
} queue_s;

int32_t queue_init(queue_s* q_in, size_t sz);

#ifdef __cplusplus
}
#endif
