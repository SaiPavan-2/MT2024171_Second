/**
Name:Q17c.c
Author:Pavan
Description:Program to execute ls -l | wc.
a. use fcntl
Date:19th september 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
int fd[2];
pipe(fd);
if (!fork()) {
close(1); 
close(fd[0]);
fcntl(fd[1], F_DUPFD, STDOUT_FILENO); 
execlp("ls", "ls", "-l", (char*) NULL);
}
else {
close(0); 
close(fd[1]);
fcntl(fd[0], F_DUPFD, STDIN_FILENO); 
execlp("wc", "wc", (char*) NULL);
}
}
/**
Output:
     47     416    2266
**/

