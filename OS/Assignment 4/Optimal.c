#include <stdio.h>
#define frame 3

int mem[frame] = {-1, -1, -1};
int pagefault = 0;
int n = 15;
int a[] = {7, 3, 5, 8, 5, 8, 3, 6, 7, 3, 6, 7, 8, 5, 3};

int predict(int index) 
{
    int i, j, pos = -1, farthest = index;
    for (i = 0; i < frame; i++) 
    {
        for (j = index; j < n; j++) 
        {
            if (mem[i] == a[j]) 
            {
                if (j > farthest) 
                {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return pos == -1 ? 0 : pos;
}

void opt(int p, int index) 
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
    for (i = 0; i < frame; i++) 
    {
        if (mem[i] == -1) 
        {
            mem[i] = p;
            return;
        }
    }
    int pos = predict(index + 1);
    mem[pos] = p;
}

int main() 
{
    int i, j;
    for (i = 0; i < n; i++) 
    {
        opt(a[i], i);
        for (j = 0; j < frame; j++) 
        {
            printf("%2d ", mem[j]);
        }
        printf("\n");
    }
    printf("\nTotal No of Pagefaults: %d", pagefault);
    return 0;
}
