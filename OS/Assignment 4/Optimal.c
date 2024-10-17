
#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
     int data;
     struct queue *next;
}Node;
Node *start=NULL,*last=NULL;
int pgfault=0,n,nof;
int a[80];
int n1;
main()
{
    int i;
    printf("\nHow many Frames\t");
    scanf("%d",&n);
    printf("\n\nEnter the no of page\t");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
         printf("\n\nEnter the Page no %d\t",i);
         scanf("%d",&a[i]);
    }
    for(i=0;i<n1;i++)
    {
	if(search(a[i])==0)
	{
		addlist(a[i]);
		pgfault++;
		printf("\nPage fault Occurs");
		print();
	}
        printf("\n");
        print();
     }
     printf("\n No of page Fault=%d",pgfault);
}
int search(int page)
{
	Node *ptr;
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
		if(ptr->data==page)
			return 1;
	return 0;
}
void print()
{
	Node *ptr;
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
		printf("%d\t",ptr->data);
	printf("\n");
}
void addlist(int page)
{
	Node *ptr=NULL;
	static int cnt=0;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=page;
	ptr->next=NULL;
	if(start==NULL)
	{
		start=last=ptr;
		cnt++;
	}
	else if(cnt<n)
	{
		last->next=ptr;
		last=ptr;
		last->next=NULL;
		cnt++;
	}
	else
	{
		last->data=ptr->data;
	}
}


