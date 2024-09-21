/**
Name:Q1a.c
Author:Pavan
Description:
Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
Date:21th  September 2024
**/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_alarm(int signum) {
    printf("ITIMER_REAL expired!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, handle_alarm);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("Error setting timer");
        return 1;
    }

    while(1) {
        pause();
    }

    return 0;
}

/**
Output:
ITIMER_REAL expired!
ITIMER_REAL expired!
ITIMER_REAL expired!
**/
