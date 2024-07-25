#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    fork();
    printf("called fork() system call\n");
    return 0;
}
