#include "pool.h"

void init_pool(pool_t *pool) {
    pool->items = malloc(PTR_SIZE * POOL_CHUNK);
    pool->free = pool->size = POOL_CHUNK;
}

void push_item(pool_t *pool, void *data) {
    if (pool->free == 0) {
        pool->items = realloc(pool->items, pool->size + POOL_CHUNK);
        pool->size += POOL_CHUNK;
        pool->free += POOL_CHUNK;
    }
    pool->items[pool->size - pool->free--] = data;
}

void pop_item(pool_t *pool, unsigned int index) {
    if (index > pool->size - pool->free)
        return;
    pool->items[index] = pool->items[pool->size - (pool->free++) - 1];
}

void free_pool(pool_t *pool) {
    free(pool->items);
}
