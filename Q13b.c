/**
Name:Q13b.c
Author:Pavan
Description:Program  sending the SIGSTOP to other program using kill().
Date:18th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Enter the pid");
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    if (kill(pid, SIGSTOP) == -1) {
        perror("kill");
        return 1;
    }

    printf("Sent SIGSTOP to process %d\n", pid);
    return 0;
}
/**Output:
Sent SIGSTOP to process 7823
**/
