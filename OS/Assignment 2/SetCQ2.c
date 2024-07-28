#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void search_file(const char *option, const char *filename, const char *pattern) {
    FILE *file = fopen(filename, "r");
    if (!file) { perror("Failed to open file"); return; }
    char line[BUFFER_SIZE]; int line_number = 0, count = 0;
    while (fgets(line, sizeof(line), file)) {
        line_number++;
        char *pos = line;
        while ((pos = strstr(pos, pattern)) != NULL) {
            if (!strcmp(option, "f")) { printf("First occurrence at line %d: %s", line_number, line); fclose(file); return; }
            else if (!strcmp(option, "a")) printf("Occurrence at line %d: %s", line_number, line);
            else if (!strcmp(option, "c")) count++;
            pos += strlen(pattern);
        }
    }
    if (!strcmp(option, "c")) printf("Total occurrences: %d\n", count);
    fclose(file);
}

int main() {
    char line[BUFFER_SIZE], *args[4], *token;
    while (1) {
        printf("myshellS$ ");
        if (!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\n")] = '\0';
        int i = 0; token = strtok(line, " ");
        while (token && i < 4) { args[i++] = token; token = strtok(NULL, " "); }
        args[i] = NULL;
        if (args[0] && !strcmp(args[0], "exit")) break;
        pid_t pid = fork();
        if (pid == -1) { perror("Fork failed"); exit(1); }
        else if (pid == 0) {
            if (args[0] && !strcmp(args[0], "search")) {
                if (args[1] && args[2] && args[3]) search_file(args[1], args[2], args[3]);
                else printf("Usage: search <f|a|c> <filename> <pattern>\n");
                exit(0);
            } else {
                execvp(args[0], args);
                perror("execvp failed");
                exit(1);
            }
        } else wait(NULL);
    }
    return 0;
}

