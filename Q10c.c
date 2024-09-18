/**
Name:Q10c.c
Author:Pavan
Description:Program using sigaction system call to catch the following signals.
a.SIGFPE
Date:17th September 2024
**/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void segfpe(int sig) {
    printf("Caught SIGFPE, divide by zero encountered.\n");
    exit(1);
}
int main() {
    struct sigaction action;
    action.sa_handler = segfpe; 
    sigemptyset(&action.sa_mask);      
    action.sa_flags = 0;               
    sigaction(SIGFPE, &action, NULL); 
    int g=0;
   printf("%d",5/g);
    return 0;
}
/**Output:Caught SIGFPE, divide by zero encountered.
**/
