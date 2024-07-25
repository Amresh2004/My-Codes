#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    printf("Before Forking\n");
    fork();
    printf("After Forking\n");
    return 0;
}