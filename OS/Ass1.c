#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process: PID = %d\n", getpid());
        printf("Child process: Parent PID = %d\n", getppid());
        
        // Sleep for 5 seconds to ensure the parent terminates before the child
        sleep(5);
        
        printf("Child process after sleep: PID = %d\n", getpid());
        printf("Child process after sleep: Parent PID = %d\n", getppid());
    } else {
        // This code is executed by the parent process
        printf("Parent process: PID = %d\n", getpid());
        printf("Parent process: Child PID = %d\n", child_pid);
        
        // Parent process terminates immediately
        printf("Parent process terminating...\n");
        exit(0);
    }

    return 0;
}