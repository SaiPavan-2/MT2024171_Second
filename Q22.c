/**
Name:Q22.c
Author:Pavan
Description:Program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date:20th September  2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>

int main() {
    char *fifo_path = "my_fifo171";
    mkfifo(fifo_path, 0666);

    int fd = open(fifo_path, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    fd_set readfds;
    struct timeval timeout;
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);
    if (ret > 0) {
        if (FD_ISSET(fd, &readfds)) {
            char buffer[100];
            read(fd, buffer, sizeof(buffer));
            printf("Data received: %s\n", buffer);
        }
    } else if (ret == 0) {
        printf("Timeout: No data within 10 seconds.\n");
    } else {
        perror("select");
    }

    close(fd);
    unlink(fifo_path);
    return 0;
}

/**
Output:
pavan@pavan-HP-Pavilion-Laptop-14-dv0xxx:~/.ssh/MT2024171_Second$ echo "Hello from FIFO" > my_fifo171
Data received: Hello from FIFO
**/
