#include <stdio.h>
#define frame 3

int mem[frame] = {-1, -1, -1};
int pagefault = 0;
int n = 15;
int a[] = {7, 3, 5, 8, 5, 8, 3, 6, 7, 3, 6, 7, 8, 5, 3};
int front = 0;

void fifo(int p) 
{
    int i;
    for (i = 0; i < frame; i++) 
    {
        if (mem[i] == p) 
        {
            return;
        }
    }
    printf("\n\nPage fault");
    pagefault++;
    mem[front] = p;
    front = (front + 1) % frame;
}

int main() 
{
    int i, j;
    for (i = 0; i < n; i++) 
    {
        fifo(a[i]);
        for (j = 0; j < frame; j++) 
        {
            printf("%2d ", mem[j]);
        }
        printf("\n");
    }
    printf("\nTotal No of Pagefaults: %d", pagefault);
    return 0;
}
