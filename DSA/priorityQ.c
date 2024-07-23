#include<stdio.h>
#define N 10
struct Element
{
    int data;
    int priority;
};
struct Element q[N];
int F = -1;
int R = -1;
void Eq()
{
    int x,priority;
    if(R == N-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter data:");
        scanf("%d",&x);
        printf("enter the priority:");
        scanf("%d",&priority);
        struct Element newElement = {x,priority};
        if(F==-1 && R==-1)
        {
            F=R=0;
            q[R]=newElement;
        }
        else
        {
            int i;
            for(i=R;i>=0;i--)
            {
                if(priority>q[i].priority)
                {
                    q[i+1]=q[i];
                }
                else
                {
                    break;
                }
            }
            q[i+1]=newElement;
            R++;
        } 
    }
}
void Dq()
{
    if(F==-1 && R==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element: data=%d, priority=%d\n",q[F].data,q[F].priority);
        if(F==R)
        {
            F=R=-1;
        }
        else
        {
            F++;
        }
    }
}
void D()
{
    if(F==-1 && R==-1)
    {
       printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is:\n");
        for(int i=F;i<=F;i++)
        {
           printf("data=%d,priority=%d\n",q[i].data,q[i].priority);
        }
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. display\n0. exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   Eq();
                   break;
            case 2:
                   Dq();
                   break;
            case 3:
                   D();
                   break;
            case 0:
                   return 0;
            default:
                    printf("Invalid choice.Try again.\n");
                    break;                            
        }
    }
}