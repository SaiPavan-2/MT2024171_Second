/**Name:Q17b.c
Author:Pavan
Description:Program to execute ls -l | wc.
a. use dup2
Date:19th september 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
int fd[2];
pipe(fd);
if (!fork()) {
close(fd[0]);
dup2(fd[1],1); 
execlp("ls", "ls", "-l", (char*) NULL);
}
else {
close(fd[1]);
dup2(fd[0],0); 
execlp("wc", "wc", (char*) NULL);
}
}
/**
Output:
      45     398    2166
**/
