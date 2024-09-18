/**
Name:Q10b.c
Author:Pavan
Description:Program using sigaction system call to catch the following signals.
b.SIGINT
Date:17th September 2024
**/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void segint(int sig) {
    printf("Caught SIGINT\n");
    exit(1);
}
int main() {
    struct sigaction action;
    action.sa_handler = segint; 
    sigemptyset(&action.sa_mask);      
    action.sa_flags = 0;               
    sigaction(SIGINT, &action, NULL); 
    while(1){
}
    return 0;
}
/**
Output:^CCaught SIGINT
**/
