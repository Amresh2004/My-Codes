#include <stdio.h>
#define frame 3

int mem[frame] = {-1, -1, -1};
int counter[frame] = {0, 0, 0};
int pagefault = 0;
int n = 15;
int a[] = {7, 3, 5, 8, 5, 8, 3, 6, 7, 3, 6, 7, 8, 5, 3};

void lru(int p, int time) {
    int k, f = 0;
    for (k = 0; k < frame; k++) {
        if (mem[k] == p) {
            counter[k] = time;
            return;
        }
    }
    printf("\n\nPage fault");
    pagefault++;
    for (k = 0; k < frame; k++) {
        if (mem[k] == -1) {
            mem[k] = p;
            counter[k] = time;
            return;
        }
    }
    for (k = 1; k < frame; k++) {
        if (counter[k] < counter[f]) {
            f = k;
        }
    }
    mem[f] = p;
    counter[f] = time;
}

int main() {
    int i, k;
    for (i = 0; i < n; i++) {
        lru(a[i], i);
        for (k = 0; k < frame; k++) {
            printf("%2d ", mem[k]);
        }
        printf("\n");
    }
    printf("\nTotal No of Pagefaults: %d", pagefault);
    return 0;
}