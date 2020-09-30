#ifndef PROTO_POOL_H
#define PROTO_POOL_H

#include <stdlib.h>

#define POOL_CHUNK 65554
#define PTR_SIZE sizeof(void *)

typedef struct pool {
    void **items;
    int free;
    int size;
} pool_t;

void init_pool(pool_t *);
void push_item(pool_t *, void *);
void pop_item(pool_t *, unsigned int);
void free_pool(pool_t *);

#endif //PROTO_POOL_H
