#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sin = { 0 };
    sin.sin_family = AF_INET;
    sin.sin_port = htons(7002);
    bind(sfd, (const struct sockaddr *) &sin, sizeof(sin));
    listen(sfd, 5);

    struct sockaddr_in c_sin;
    socklen_t sin_size = sizeof(c_sin);
    int cfd = accept(sfd, (struct sockaddr *) &c_sin, &sin_size);

    char BUFFER[4096] = { 0 };
    int count = 0;
    while ((count = read(cfd, &BUFFER, 32))) {
        write(STDOUT_FILENO, BUFFER, count);
    }

    close(cfd);
    close(sfd);

    return 0;
}
