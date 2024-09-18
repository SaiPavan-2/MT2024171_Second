/**
Name:Q12.c
Author:Pavan
Description:Program to create an orphan process and  use kill system call to send SIGKILL signal to
the parent process from the child process.
Date:18th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error in fork");
        exit(1);
    } 
    else if (pid > 0) {
        printf("Parent process PID is %d\n", getpid());
        sleep(10);
    } 
    else {
        printf("Child process  PID is %d, Parent PID is %d\n", getpid(), getppid());
        printf("Child is killing the parent\n");
        kill(getppid(), SIGKILL);
        sleep(5);
        printf("Child process is orphan, new Parent PID is %d\n", getppid());
	exit(0);
    }

    return 0;
}
/**
Output:
Parent process PID is 5693
Child process  PID is 5694, Parent PID is 5693
Child is killing the parent
Killed
pavan@pavan-HP-Pavilion-Laptop-14-dv0xxx:~/.ssh/MT2024171_Second$ Child process is orphan, new Parent PID is 1740
**/
