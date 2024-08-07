#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_TOKENS 100

void countFile(const char *filename, char mode)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("fopen");
        return;
    }

    int count = 0;
    int c;
    int in_word = 0;

    while ((c = fgetc(file)) != EOF)
    {
        if (mode == 'c')
        {
            count++;
        }
        else if (mode == 'w')
        {
            if (c == ' ' || c == '\n' || c == '\t')
            {
                if (in_word)
                {
                    count++;
                    in_word = 0;
                }
            }
            else
            {
                in_word = 1;
            }
        }
        else if (mode == 'l')
        {
            if (c == '\n')
            {
                count++;
            }
        }
    }
    if (mode == 'w' && in_word)
    {
        count++;
    }

    fclose(file);
    printf("%d\n", count);
}

void executeCommand(char **args)
{
    if (strcmp(args[0], "count") == 0)
    {
        if (args[1] && args[2])
        {
            countFile(args[2], args[1][0]);
        }
        else
        {
            printf("Usage: count <c|w|l> <filename>\n");
        }
    }
    else
    {
        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork");
        }
        else if (pid == 0)
        {
            if (execvp(args[0], args) == -1)
            {
                perror("execvp");
                exit(1);
            }
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

int main()
{
    char cmd[MAX_CMD_LEN];
    char *args[MAX_TOKENS];
    char *token;

    while (1)
    {
        printf("myshell$ ");
        if (!fgets(cmd, sizeof(cmd), stdin))
        {
            break; 
        }
        cmd[strcspn(cmd, "\n")] = '\0';
        int i = 0;
        token = strtok(cmd, " ");
        while (token && i < MAX_TOKENS - 1)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;
        if (args[0])
        {
            executeCommand(args);
        }
    }
    return 0;
}

