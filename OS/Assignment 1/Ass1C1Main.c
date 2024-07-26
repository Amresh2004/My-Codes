#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        char *args[n + 3];
        char buffer[20];
        
        args[0] = "./Ass1C1Second";
        sprintf(buffer, "%d", n);
        args[1] = buffer;

        for (i = 0; i < n; i++) {
            sprintf(buffer, "%d", arr[i]);
            args[i + 2] = strdup(buffer);
        }
        args[n + 2] = NULL;

        execve("./Ass1C1Second", args, NULL);
        perror("execve");
        exit(1);
    } else {
        // Parent process
        wait(NULL);
        printf("Child process completed\n");
    }

    return 0;
}