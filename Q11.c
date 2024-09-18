/**
Name:Q11.c
Author:Pavan
Description:Program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
using  sigaction system call.
Date:17th September 2024
**/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction action;

    action.sa_handler = SIG_IGN;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGINT, &action, NULL);
    printf("SIGINT is now being ignored.\n");
    sleep(5);

    action.sa_handler = SIG_DFL;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGINT, &action, NULL);
    printf("SIGINT is now reset to its default action.\n");
    sleep(5);

    return 0;
}
/**Output:
SIGINT is now being ignored.
^CSIGINT is now reset to its default action.
^C
**/

