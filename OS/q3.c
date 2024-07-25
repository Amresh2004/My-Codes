#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t pid,mypid,myppid;
    pid=getpid();
    printf("Before fork: process id is %d\n",pid);
    pid=fork();
    if(pid<0)
    {
        printf("fork() Falied");
        return 1;
    }
    if(pid==0)
    {
        printf("This is Child Process\n");
        mypid=getpid();
        myppid=getppid();
        printf("Process id is %d & PPID is %d\n",mypid,myppid);
    }
    else{
        sleep(5);
        printf("This is parent process\n");
        mypid=getpid();
        myppid=getppid();
        printf("Process id is %d & PPID is %d\n",mypid,myppid);
        printf("newely created process id or chlid id is %d\n",pid);
    }
    return 0;
}