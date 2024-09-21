/**
Name:Q23.c
Author:Pavan
Description:Program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 20th September 2024
**/
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));

    long pipe_size = fpathconf(STDOUT_FILENO, _PC_PIPE_BUF);
    if (pipe_size != -1) {
        printf("Pipe size: %ld bytes\n", pipe_size);
    } else {
        perror("fpathconf");
    }

    return 0;
}

/**
Output:
Max open files: 1024
Pipe size: 4096 bytes
**/
