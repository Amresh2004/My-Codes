/*

#include<stdio.h>
#include<stdlib.h>

typedef struct queue 
{
	int data;
	struct queue *next;
} Node;

Node *start = NULL, *last = NULL, *ptr;
int pgfault = 0, n, nof;
int a[80];
int n1, i, k, min = 0;

void printUI(int page, int page_fault) 
{
    printf("\n------------------------------------------------");
    printf("\n Page Request : %2d ", page);
    Node *temp;
    for (temp = start; temp != NULL; temp = temp->next) 
    {
        printf(" |      %2d ", temp->data);
    }
    printf(" |   -->   Page Faults: %d", page_fault);
    printf("\n------------------------------------------------");
}

int search(int page) 
{
    for (ptr = start; ptr != NULL; ptr = ptr->next) 
    {
        if (page == ptr->data)
            return 1;
    }
    return 0;
}

void addlist(int page) 
{
    Node *ptr = NULL, *temp, *ptr1 = NULL, *prev = NULL;
    int cnt1 = 1;
    static int cnt = 0;
    int j;

    ptr = (Node *)malloc(sizeof(Node));
    ptr->data = page;
    ptr->next = NULL;

    if (start == NULL) 
    {  // Empty queue
        start = last = ptr;
        cnt++;
    } 
    else if (cnt < n) 
    {  // Less than max frames
        last->next = ptr;
        last = ptr;
        last->next = NULL;
        cnt++;
    } 
    else 
    {  // Replace page using LRU
        min = 0;
        k = 0;

        for (temp = start; temp != NULL; prev = temp, temp = temp->next) 
	{
            for (j = i + 1; j < n1; j++) 
	    {
                if (a[j] == temp->data) 
		{
                    k = j;
                    break;
                }
            }
            if (min <= k) 
	    {
                min = k;
                ptr1 = temp;
            }
        }

        if (ptr1 == start) 
	{  // If victim page is first
            start = start->next;
            free(ptr1);
            last->next = ptr;
            last = ptr;
        } 
	else if (ptr1 == last) 
	{  // If victim page is last
            last->data = ptr->data;
        } 
	else 
	{  // Victim is in the middle
            prev->next = ptr1->next;
            free(ptr1);
            last->next = ptr;
            last = ptr;
        }
    }
}

void print() 
{
    Node *ptr;
    printf("\nCurrent Frame: ");
    for (ptr = start; ptr != NULL; ptr = ptr->next)
        printf("%d\t", ptr->data);
    printf("\n\n");
}

int main() 
{
    printf("\nHow many Frames? ");
    scanf("%d", &n);

    printf("\nEnter the number of pages: ");
    scanf("%d", &n1);

    for (i = 0; i < n1; i++) 
    {
        printf("\nEnter the Page no %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n1; i++) 
    {
        if (search(a[i]) == 0) 
	{
            addlist(a[i]);
            pgfault++;
            printf("\nPage fault Occurs");
            print();
        }
        printUI(a[i], pgfault);
    }
    
    printf("\nTotal number of Page Faults = %d\n", pgfault);
    
    return 0;
}
*/


#include<stdio.h>
#define frame 3
int mem[frame][2]={-1,0,-1,0,-1,0};
int pagefault=0;
int n=15;
int a[]={7,3,5,8,5,8,3,6,7,3,6,7,8,5,3};
void mfu(int p)
{
    int k,f=0;
    for(k=0;k<frame;k++)
    {
        if(mem[k][0]==p)
        { 
           mem[k][1]=mem[k][1]+1;
           return;
        }
    } 
    printf("\n\n Page fault");
    pagefault++;
    for(k=0;k<frame;k++)
       if(mem[k][0]==-1)
       {
          mem[k][0]=p;
          mem[k][1]=0;
          return;
       }
     for(k=0;k<frame;k++)
        if(mem[k][1]<mem[f][1])
            f=k;
            mem[f][0]=p;
            mem[f][1]=0;
}
main()
{
    int i=0,k;
    for(i=0;i<n;i++) 
    {
       mfu(a[i]);
       for(k=0;k<frame;k++)
           printf("%2d",mem[k][0]);
           printf("\n\n");
     }
    printf("\nTotal No of Pagefault : %d",pagefault);
}
