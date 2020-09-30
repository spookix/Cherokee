#ifndef PROTO_POOL_H
#define PROTO_POOL_H

#include <stdlib.h>
#include <string.h>

#define SIZE_POOL 4096

typedef struct pool {
    int used;
    int size;
    size_t p_size;
    void **items;
} pool_t;

pool_t *pool_init(size_t ptr_size);
void *pool_new(pool_t *pool, int *index);
void pool_pop(pool_t *pool, unsigned int);
void pool_free(pool_t *pool);

#endif //PROTO_POOL_H
