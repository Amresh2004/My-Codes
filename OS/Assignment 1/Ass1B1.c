/*Implement the C program to accept n integers to be sorted. Main function creates child
process using fork system call. Parent process sorts the integers using bubble sort and
waits for child process using wait system call. Child process sorts the integers using
insertion sort.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Bubble sort function
void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Insertion sort function
void insertionSort(int a[], int n)
{
    int i, j, key;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Function to print array
void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    // Accept the number 'n' of integers
    printf("Enter the number 'n' of integers: ");
    scanf("%d", &n);
    int a[n];
    // Accept integers
    printf("Enter the integers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process sorting using insertion\n");
        insertionSort(a, n);
        printf("Child process sorted array: ");
        printArray(a, n);
    }
    else
    {
        // Parent process
        wait(NULL); // Wait for child to complete
        printf("Parent process sorting using bubble\n");
        bubbleSort(a, n);
        printf("Parent process sorted array: ");
        printArray(a, n);
    }
}