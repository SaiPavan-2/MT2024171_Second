/**
Name:Q14.c
Author:Pavan
Description:Program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date:18th September 2024
**/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[100];
    pipe(fd);
    const char *message = "Data passed through the pipe";
    write(fd[1], message, strlen(message) + 1);
    close(fd[1]);
    read(fd[0], buffer, sizeof(buffer));
    printf("Read from the pipe: %s\n", buffer);
    close(fd[0]);
    return 0;
}
/**
Output:Read from the pipe: Data passed through the pipe
**/

