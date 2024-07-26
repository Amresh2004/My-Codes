/*Write a program that demonstrates the use of nice() system call. After a child process is
started using fork(), assign higher priority to the child using nice() system call.*/
// nice() +19 low to -20 high priority

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid; // pid_t type of pid
    pid = fork();
    if (pid == 0)
    {
        // This is child
        printf("I am child Process. ID = %d\n", getpid());
        printf("priority = %d ,ID = %d\n", nice(-20), getpid());
    }
    else
    {
        // This is parent
        printf("I am parent Process. ID = %d\n", getpid());
        printf("priority = %d , ID = %d\n", nice(19), getpid());
    }
}