#include <stdio.h>
#define frame 3

int mem[frame] = {-1, -1, -1};
int counter[frame] = {0, 0, 0};
int pagefault = 0;
int n = 15;
int a[] = {3,5,7,2,5,1,2,3,1,3,5,3,1,6,2};

void lru(int p, int time) 
{
    int i, f = 0;
    for (i = 0; i < frame; i++) 
    {
        if (mem[i] == p) 
        {
            counter[i] = time;
            return;
        }
    }
    printf("\n\nPage fault");
    pagefault++;
    for (i = 0; i < frame; i++) 
    {
        if (mem[i] == -1) 
        {
            mem[i] = p;
            counter[i] = time;
            return;
        }
    }
    for (i = 1; i < frame; i++) 
    {
        if (counter[i] < counter[f]) 
        {
            f = i;
        }
    }
    mem[f] = p;
    counter[f] = time;
}

int main() {
    int i, j;
    for (i = 0; i < n; i++) 
    {
        lru(a[i], i);
        for (j = 0; j < frame; j++) 
        {
            printf("%2d ", mem[j]);
        }
        printf("\n");
    }
    printf("\nTotal No of Pagefaults: %d", pagefault);
    return 0;
}
