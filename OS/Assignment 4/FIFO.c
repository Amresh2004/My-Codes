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
int n1, i;

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
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = page;
    ptr->next = NULL;

    if (start == NULL) 
    {  // Queue is empty
        start = last = ptr;
    } 
    else if (nof < n) 
    {  // Less than max frames
        last->next = ptr;
        last = ptr;
    } 
    else 
    {  // FIFO replacement
        Node *temp = start;
        start = start->next;  // Remove the oldest page (first one in the list)
        free(temp);
        last->next = ptr;
        last = ptr;
    }

    nof++;  // Increment number of frames used
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
	{  // Page not found in memory, page fault
            addlist(a[i]);  // Add page to the frame (FIFO replacement)
            pgfault++;
            printf("\nPage fault Occurs");
            print();
        }
        printUI(a[i], pgfault);
    }
    
    printf("\nTotal number of Page Faults = %d\n", pgfault);
    
    return 0;
}
