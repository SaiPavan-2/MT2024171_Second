/**
Name:Q8e.c
Author:Pavan
Description:
SIGVTALRM (use setitimer system call)
Date:21th September 2024
**/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_sigvtalrm(int sig) {
    printf("SIGVTALRM received! Virtual timer expired.\n");
}

int main() {
    struct itimerval timer;

    signal(SIGVTALRM, handle_sigvtalrm);

    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1) {}

    return 0;
}
/**
Output:
**/

