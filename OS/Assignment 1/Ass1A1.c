/*Implement the C Program to create a child process using fork(), display parent and child
process id. Child process will display the message “I am Child Process” and the parent
process should display “I am Parent Process”.*/
// 0 if child Process
//-ve if child not created
//+ve if parent Process
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    // pid_t pid;
    // pid process id
    //  Create child
    int pid = fork();
    if (pid > 0)
    {
        // This is parent
        printf("I am parent Process\n");
        printf("My Process ID: %d\n\n", getpid());
    }
    else if (pid == 0)
    {
        // This is child
        printf("I am Child Process\n");
        printf("My Process ID: %d\n\n", getpid());
        // getpid() will return pid of Child
    }
    else
    {
        printf("Failed to create Child Process\n");
    }
}