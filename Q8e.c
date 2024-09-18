/**
Name:Q8e.c
Author:Pavan
Description:Program using signal system call to catch the following signal.
c.  SIGALRM 
Date:17th September 2024
**/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigalrm_handler(int sig) {
    printf("SIGALRM received: Timer expired!\n");
}

int main() {
    struct itimerval tmr;

    signal(SIGALRM, sigalrm_handler);

    tmr.it_value.tv_sec = 2;
    tmr.it_value.tv_usec = 0;

    tmr.it_interval.tv_sec = 3;
    tmr.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &tmr, NULL);

    while (1) {
        pause();
    }

    return 0;
}
/**
Output:SIGALRM received: Timer expired!
SIGALRM received: Timer expired!
SIGALRM received: Timer expired!
SIGALRM received: Timer expired!
**/
