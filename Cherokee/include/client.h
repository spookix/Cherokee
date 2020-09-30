#ifndef CHEROKEE_CLIENT_H
#define CHEROKEE_CLIENT_H

#include <netinet/in.h>

typedef struct {
    int sock;
    struct sockaddr_in addr;
    socklen_t addr_size;
    request request;
} Client;

#endif //CHEROKEE_CLIENT_H
