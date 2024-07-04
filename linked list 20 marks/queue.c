#include<stdio.h>
#define N 10
int q[N];
int F=-1;
int R=-1;
void Eq()
{
    int a,x,i;
    if(R==N-1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("\n Enter the size of Q:");
        scanf("%d",&a);
        for(i=0;i<a;i++)
        {
            printf("\n Enter the data %d:",i+1);
            scanf("%d",&x);
            R++;
            q[R]=x;
        }
    }
}
void Dq()
{
    if(F == -1 && R == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element: %d\n",q[F]);
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
    if(F == -1 && R == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is:\n");
        for(int i=F+1; i<=R;i++)
        {
            printf("%d\n",q[i]);
        }
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n 1. Enqueue\n 2. dequeue\n 3. Display\n 0. exit\n");
        printf("Enter the choice:");
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
                printf("invalid choice. try again.\n");
                break;    
        }
    }
}