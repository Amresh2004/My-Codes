#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t pid=fork();
    if(pid>0)
    {
        printf("Parent Process\n");
        printf("Id %d\n",getpid());
    }
    else if(pid==0)
    {
        printf("Child Process\n");
        printf("Id %d\n",getgid());
        printf("Parent Id %d\n",getppid());
        sleep(10);
        printf("Child Process\n");
        printf("Id %d\n",getpid());
        printf("Parent Id %d\n",getppid());
    }
    else{
        printf("Fork Failed\n");
    }
    return 0;
}