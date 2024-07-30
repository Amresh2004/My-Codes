#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_CMD_LEN 1024
#define MAX_TOKENS 100

void search_file(const char *filename, const char *pattern, char mode) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[1024];
    int line_num = 0, count = 0;

    while (fgets(line, sizeof(line), file)) {
        line_num++;
        char *pos = line;
        while ((pos = strstr(pos, pattern)) != NULL) {
            if (mode == 'f') {
                printf("First occurrence at line %d: %s", line_num, line);
                fclose(file);
                return;
            } else if (mode == 'a') {
                printf("Occurrence at line %d: %s", line_num, line);
                pos += strlen(pattern);
            } else if (mode == 'c') {
                count++;
                pos += strlen(pattern);
            }
        }
    }

    if (mode == 'c') {
        printf("Total occurrences: %d\n", count);
    }

    fclose(file);
}

void executeCommand(char **args) {
    if (strcmp(args[0], "search") == 0) {
        if (args[1] && args[2] && args[3]) {
            search_file(args[2], args[3], args[1][0]);
        } else {
            printf("Usage: search <f|a|c> <filename> <pattern>\n");
        }
    } else {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }
    }
}

int main() {
    char cmd[MAX_CMD_LEN], *args[MAX_TOKENS], *token;

    while (1) {
        printf("myshell$ ");
        if (!fgets(cmd, sizeof(cmd), stdin)) break;
        cmd[strcspn(cmd, "\n")] = '\0';

        int i = 0;
        token = strtok(cmd, " ");
        while (token && i < MAX_TOKENS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (args[0]) {
            if (strcmp(args[0], "exit") == 0) break;
            executeCommand(args);
        }
    }

    return 0;
}


AFTER CRETAE a.txt file In that write:
a.txt:-
    This is a sample file.
    This file is used to demonstrate the search functionality. 
    We will search for a pattern in this file.
    The pattern might be found multiple times.
    Let's see how the search command works.
    Search can be done for the first occurrence, all occurrences, or just count them.
    This is the end of the sample file.

    
OUTPUT:-
    myshell$ search f a.txt pattern
             First occurrence at line 4: We will search for a pattern in this file.
    myshell$ search a a.txt pattern
             Occurrence at line 4: We will search for a pattern in this file.
             Occurrence at line 5: The pattern might be found multiple times.
    myshell$ search c a.txt pattern
T            total occurrences: 2
