#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

void display_lines(const char *filename, int n, int mode) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    char line[1024];
    int total_lines = 0, skip_lines = 0;

    if (mode == 1) {
        while (fgets(line, sizeof(line), file)) total_lines++;
        fseek(file, 0, SEEK_SET);
        skip_lines = total_lines > n ? total_lines - n : 0;
    }

    for (int i = 0; mode == 0 ? i < n && fgets(line, sizeof(line), file) : fgets(line, sizeof(line), file); i++) {
        if (mode == 2 || (mode == 0 && i < n) || (mode == 1 && i >= skip_lines)) {
            printf("%s", line);
        }
    }
    fclose(file);
}

int main() {
    char line[1024], *args[100], *token;
    while (1) {
        printf("myshell$ ");
        if (!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\n")] = '\0';
        int i = 0;
        token = strtok(line, " ");
        while (token) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;
        if (args[0] && !strcmp(args[0], "exit")) break;

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            if (args[0] && !strcmp(args[0], "typeline")) {
                if (args[1] && args[2]) {
                    if (!strcmp(args[1], "a")) display_lines(args[2], 0, 2);
                    else if (args[1][0] == '-') display_lines(args[2], atoi(args[1] + 1), 1);
                    else display_lines(args[2], atoi(args[1]), 0);
                } else {
                    printf("Usage: typeline <n|-n|a> <filename>\n");
                }
                exit(0);
            } else {
                execvp(args[0], args);
                perror("execvp failed");
                exit(1);
            }
        } else {
            wait(NULL);
        }
    }
    return 0;
}
