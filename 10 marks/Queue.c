#include<stdio.h>
#include<stdlib.h>
#define N 5
int q[N];
int front,rear=-1;
void Enqueue(int x)
{
    int a,i;
    if(rear==N-1)
    {
        printf("Queue is Full");
    }
    else if(front ==-1 && rear==-1)
    {
        front=rear=0;
        q[rear]=x;
    }
    else
    {
        printf("\n ENter the size of Queue\n");
        scanf("%d",&a);
        for(i=0;i<a;i++)
        {
            printf("\nENter the elements To Push\n");
            scanf("%d",&x);
            rear++;
            q[rear]=x;
        }
    }
}
void Dequeue(int x)
{
    if(front ==-1 && rear ==-1)
    {
        printf("Queue is Empty");
    }
    else if(front==rear)
    {
        front=rear=1;
    }
    else
    {
        printf("Deleted elements %d\n",q[front]);
        front++;
    }
}
void peek(int x)
{
    if(front==-1 && rear==-2)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("%d",q[front]);
    }
}
void Display(int x)
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\n Elements in Queue\n");
        for(i=front;i<rear+1;i++)
        {
            printf("%d\t",q[i]);
        }
    }
}
int main()
{
    int ch;
    printf("\n1.Enqueue \n2.display \n3.Dequeue \n4.peek \n0.exit");
    while(1)
    {
        printf("Enetr the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   Enqueue(N);
                   break;
            case 2:
                   Display(N);
                   break;
            case 3:
                   Dequeue(N);
                   break;
            case 4:
                   peek(N);
                   break;
            case 0:
                   exit(N);
                   break;
            default:
                    printf("Invalid choice");
                    break;                                   
        }
    }
}