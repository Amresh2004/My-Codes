#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>

void list_directory(const char *option, const char *dirname) {
    DIR *dir = opendir(dirname);
    if (!dir) { perror("opendir"); return; }
    struct dirent *entry;
    int count = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;
        if (!strcmp(option, "f")) printf("%s\n", entry->d_name);
        else if (!strcmp(option, "n")) count++;
        else if (!strcmp(option, "i")) printf("%s (inode: %ld)\n", entry->d_name, (long)entry->d_ino);
        else { printf("Invalid option\n"); closedir(dir); return; }
    }
    if (!strcmp(option, "n")) printf("Total entries: %d\n", count);
    closedir(dir);
}

int main() {
    char line[1024], *args[100], *token;
    while (1) {
        printf("myshellS$ ");
        if (!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\n")] = '\0';
        int i = 0;
        token = strtok(line, " ");
        while (token) { args[i++] = token; token = strtok(NULL, " "); }
        args[i] = NULL;
        if (args[0] && !strcmp(args[0], "exit")) break;
        pid_t pid = fork();
        if (pid == -1) { perror("fork"); exit(1); }
        else if (pid == 0) {
            if (args[0] && !strcmp(args[0], "list")) {
                if (args[1] && args[2]) list_directory(args[1], args[2]);
                else printf("Usage: list <f|n|i> <dirname>\n");
                exit(0);
            } else { execvp(args[0], args); perror("execvp"); exit(1); }
        } else wait(NULL);
    }
    return 0;
}

