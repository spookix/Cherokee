#include <stdio.h>
#include "pool/pool.h"

int main() {
    pool_t pool;
    char letters[5] = { 'a', 'b', 'c', 'd', 'e' };

    init_pool(&pool);
    push_item(&pool, &letters[0]);
    push_item(&pool, &letters[1]);
    pop_item(&pool, 0);
    push_item(&pool, &letters[2]);
    push_item(&pool, &letters[0]);

    for (int i = 0; i < (pool.size - pool.free); i++) {
        printf("%c\n", *(char *)(pool.items[i]));
    }

    free_pool(&pool);

    return 0;
}
