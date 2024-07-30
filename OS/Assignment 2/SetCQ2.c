#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_CMD_LEN 1024
#define MAX_TOKENS 100

void listDirectory(char mode, char *dirname) {
    struct dirent *entry;
    DIR *dp = opendir(dirname);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    if (mode == 'f') {
        while ((entry = readdir(dp)) != NULL) {
            printf("%s\n", entry->d_name);
        }
    } else if (mode == 'n') {
        int count = 0;
        while ((entry = readdir(dp)) != NULL) {
            count++;
        }
        printf("%d\n", count);
    } else if (mode == 'i') {
        while ((entry = readdir(dp)) != NULL) {
            struct stat fileStat;
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
            if (stat(path, &fileStat) == -1) {
                perror("stat");
                continue;
            }
            printf("%s - %lu\n", entry->d_name, fileStat.st_ino);
        }
    }

    closedir(dp);
}

void executeCommand(char **args) {
    if (strcmp(args[0], "list") == 0) {
        if (args[1] && args[2]) {
            struct stat sb;
            if (stat(args[2], &sb) == 0 && S_ISDIR(sb.st_mode)) {
                listDirectory(args[1][0], args[2]);
            } else {
                printf("Dir %s not found.\n", args[2]);
            }
        } else {
            printf("Usage: list <f|n|i> dirname\n");
        }
    } else {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
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
        if (args[0]) executeCommand(args);
    }
    return 0;
}

Run:-
myshell$ list f .
myshell$ list n /etc
myshell$ list i /usr/bin
