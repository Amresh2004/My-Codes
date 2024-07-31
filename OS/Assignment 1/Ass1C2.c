/*Implement the C Program to create a child process using fork(), Using exec() system call,
child process will execute the program specified in Set A(1) and parent will continue by
printing message “I am parent “.*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    // Fork a child
    pid_t pid = fork();

    if (pid > 0)
    {
        // Fork failed
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        // Path to the program to execute
        char *program = "./Ass1A1"; // Ass1A1 is already written
        char *args[] = {program, NULL};
        char *env[] = {NULL}; // Pass empty environment

        // Execute the child program
        execve(program, args, env);

        // If execve returns, there was error
        perror("execve failed");
        exit(1);
    }
    else
    {
        // Parent process
        // Wait for child to complete
        wait(NULL);
        // Print message from parent process
        printf("I am parent\n");
    }
}