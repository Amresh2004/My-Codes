#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid = fork();
    if (pid > 0)
    {
        printf("I am parent Process\n");
        printf("My Process ID: %d\n\n", getpid());
    }
    else if (pid == 0)
    {
        printf("I am Child Process\n");
        printf("My Process ID: %d\n\n", getpid());
    }
    else
    {
        printf("Failed to create Child Process\n");
    }
}
