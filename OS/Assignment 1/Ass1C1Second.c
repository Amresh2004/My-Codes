#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <n> <sorted_array>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 2]);
    }

    int x;
    printf("Enter the number to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element %d is not present in the array\n", x);
    else
        printf("Element %d is present at index %d\n", x, result);

    return 0;
}