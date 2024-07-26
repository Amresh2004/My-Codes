/*Write a C program to illustrate the concept of orphan process. Parent process creates a
child and terminates before child has finished its task. So child process becomes orphan
process. (Use fork(), sleep(), getpid(), getppid())*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process started with PID: %d\n", getpid());
        printf("Child process's parent PID: %d\n", getppid());
        // Sleep for a while to ensure parent process terminates first
        sleep(5);
        // Now the child process should be an orphan and adopted by init (PID 1)
        printf("Child process after parent termination, new parent PID: %d\n", getppid());
        printf("Child process is doing some work....\n");
        // Simulate some work by sleeping
        sleep(10);
        printf("Child process completed work and exiting.\n");
    }
    else
    {
        // Parent process
        printf("Parent process with PID: %d is terminating before child completes.\n", getpid());
        // Sleep for a short time to ensure child is still running
        sleep(2);
        printf("Parent process exiting.\n");
        exit(0);
    }
}