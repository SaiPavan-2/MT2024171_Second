/**
Name:Q10a.c
Author:Pavan
Description:Program using sigaction system call to catch the following signals.
a.SIGSEV
Date:17th September 2024
**/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void segv(int sig) {
    printf("Caught SIGSEGV, segmentation Fault occurred.\n");
    exit(1);
}
int main() {
    struct sigaction action;
    action.sa_handler = segv; 
    sigemptyset(&action.sa_mask);      
    action.sa_flags = 0;               
    sigaction(SIGSEGV, &action, NULL); 
    int *ptr = NULL;
    *ptr = 13;

    return 0;
}
/**Output:Caught SIGSEGV, segmentation Fault occurred.
**/
