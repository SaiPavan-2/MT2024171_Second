/**
Name:Q34b.c
Author:Pavan
Description:
use pthread_create
Date:21th September 2024
**/
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#define PORT 8080
#define BACKLOG 5

void *handle_client(void *socket_desc) {
    int new_socket = *(int*)socket_desc;
    char buffer[1024] = {0};
    char *message = "Hello from server";

    read(new_socket, buffer, 1024);
    printf("Client: %s\n", buffer);
    send(new_socket, message, strlen(message), 0);
    printf("Message sent from server\n");
    close(new_socket);
    free(socket_desc);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, BACKLOG);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        pthread_t thread_id;
        int *new_sock = malloc(sizeof(int));
        *new_sock = new_socket;

        pthread_create(&thread_id, NULL, handle_client, (void*)new_sock);
        pthread_detach(thread_id);
    }

    return 0;
}

/**Output:
pavan@pavan-HP-Pavilion-Laptop-14-dv0xxx:~/.ssh/MT2024171_2$ telnet localhost 8080
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
pavan
Hello from serverConnection closed by foreign host.
**/


