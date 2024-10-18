#include <stdio.h>
#define frame 3

int mem[frame] = {-1, -1, -1};
int pagefault = 0;
int n = 15;
int a[] = {3,4,5,6,3,4,7,3,4,5,6,7,2,4,6};
int front = 0;

void fifo(int p) 
{
    int i;
    for (i = 0; i< frame; i++) 
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
    int i, k;
    for (i = 0; i < n; i++) 
    {
        fifo(a[i]);
        for (k = 0; k < frame; k++) 
        {
            printf("%2d ", mem[k]);
        }
        printf("\n");
    }
    printf("\nTotal No of Pagefaults: %d", pagefault);
    return 0;
}
