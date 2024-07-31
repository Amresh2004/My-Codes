/*#include <stdio.h>
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

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

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

CREATE COMPILE AND RUN:-
    vim sort.c
    vim binary_serach.c
    amresh2004@Amresh:~$ vim binary_search.c
    amresh2004@Amresh:~$ vim binary_serach.c
    amresh2004@Amresh:~$ gcc sort.c -o sort
    amresh2004@Amresh:~$ gcc binary_serach.c -o binary_search
    amresh2004@Amresh:~$ ./sort 4 6 8 3

OUTPUT:-
    Sorted array: 3 4 6 8
    Enter the number to search: 3
    Element found at index: 0
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    pid_t pid = fork();
    if (pid == 0) {
        pause();
    } else if (pid > 0) {
        bubbleSort(a, n);
        printf("Sorted array:");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        char *args[n + 2];
        args[0] = "./binary_search";
        for (int i = 0; i < n; ++i) {
            args[i + 1] = malloc(10);
            snprintf(args[i + 1], 10, "%d", a[i]);
        }
        args[n + 1] = NULL;

        kill(pid, SIGCONT);
        execve("./binary_search", args, NULL);
        perror("execve");
    } else {
        perror("Fork failed");
    }

    return 0;
}

