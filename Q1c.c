/**
Name:Q1c.c
Author:Pavan
DEscription:
c. ITIMER_PROF
Date:21th September  2024
**/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_profalarm(int signum) {
    printf("ITIMER_PROF expired!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, handle_profalarm);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("Error setting timer");
        return 1;
    }

    while(1) {
        for (volatile int i = 0; i < 100000000; i++);
    }

    return 0;
}
/**
Output:
ITIMER_PROF expired!
ITIMER_PROF expired!
**/

