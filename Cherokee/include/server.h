#ifndef CHEROKEE_SERVER_H
#define CHEROKEE_SERVER_H

#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "request.h"
#include "client.h"

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define D_CRLF      "\r\n\r\n"
#define CRLF		"\r\n"
#define BUF_SIZE	10000
#define RESPONSE "HTTP/1.1 200 OK\r\n\r\n"

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

int init_connection(void);
int read_request(Client *client);
bool request_ready(Client *client);
void write_client(Client *client, const char *buffer);
Client *accept_client(SOCKET server, Client *client);
void close_client(Client *client);

#endif //CHEROKEE_SERVER_H
