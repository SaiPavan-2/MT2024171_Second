/**
Name:Q15.c
Author:Pavan
Description:Program to send some data from parent to the child process.
Date:19th September 2024
**/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(){
char buff[100];
int fd[2];
pipe(fd);
if(fork()){
close(fd[0]);
printf("Enter the data to be sent to the child\n");
scanf(" %[^\n]",buff);
write(fd[1],buff,sizeof(buff));
close(fd[1]);
}
else{
close(fd[1]);
read(fd[0],buff,sizeof(buff));
printf("Message from parent %s\n",buff);
}
exit(0);
}
/**
Output:Enter the data to be sent to the child
Hello child
Message from parent Hello child
**/

