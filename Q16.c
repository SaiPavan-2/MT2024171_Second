/**
Name:Q16.c
Author:Pavan
Description:Program to send and receive data from parent to child vice versa. Use two way
communication.
Date:19th september 2024
**/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd1[2];
    int fd2[2];
    char buff1[100];
    char buff2[100];
    
    pipe(fd1);
    pipe(fd2);

    if (!fork()) {
        close(fd1[0]);
        close(fd2[1]);
        printf("Enter the text to be sent to the parent: ");
        scanf(" %[^\n]", buff1);
        write(fd1[1], buff1, sizeof(buff1));
        read(fd2[0], buff2, sizeof(buff2));
        printf("The data received by the child is: %s\n", buff2);
        close(fd1[1]);
        close(fd2[0]);
    } else {
        close(fd2[0]);
        close(fd1[1]);
        read(fd1[0], buff1, sizeof(buff1));
        printf("The data received by the parent is: %s\n", buff1);
        printf("Enter the data to be sent to the child: ");
        scanf(" %[^\n]", buff2);
        write(fd2[1], buff2, sizeof(buff2));
        close(fd2[1]);
        close(fd1[0]);
    }

    return 0;
}
/**
Output:
Enter the text to be sent to the parent: Hello Parent
The data received by the parent is: Hello Parent
Enter the data to be sent to the child: Hello Child
The data received by the child is: Hello Child
**/
