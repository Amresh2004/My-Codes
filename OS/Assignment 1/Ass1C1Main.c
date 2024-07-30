#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 128

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    sort(arr, n);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        char *new_argv[MAX_ARGS];
        new_argv[0] = "./binary_search"; // New program to be executed

        for (int i = 0; i < n; i++) {
            new_argv[i + 1] = malloc(10);
            sprintf(new_argv[i + 1], "%d", arr[i]);
        }

        new_argv[n + 1] = NULL;

        if (execve(new_argv[0], new_argv, NULL) == -1) {
            perror("execve failed");
        }
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}

SAVE AS sort.c
after code do the compile code
     gcc sort.c -o sort
     gcc binary_search -o binary_search
     ./sort 5 7 6 4
     OUTPUT:-
     Enter the number to be Search:- 5
     Enterd number INdex :- 0;
