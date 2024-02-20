#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // Get the process ID of the parent process
    pid_t parentPID = getpid();

    // Fork the process
    pid_t childPID = fork();

    if (childPID == -1) {
        // Error handling if fork fails
        fprintf(stderr, "Fork failed.\n");
        return 1;
    }

    if (childPID == 0) {
        // Code executed by the child process
        printf("Child process ID: %d, Parent process ID: %d\n", getpid(), parentPID);
    } else {
        // Code executed by the parent process
        printf("Parent process ID: %d, Child process ID: %d\n", parentPID, childPID);
    }

    return 0;
}
