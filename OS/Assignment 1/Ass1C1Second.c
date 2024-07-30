#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sorted list of integers>\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = binary_search(arr, n, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}

