#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // This block is executed by the child process
        printf("Child process PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
        // This block is executed by the parent process
        printf("Parent process PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}
