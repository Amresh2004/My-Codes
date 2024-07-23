#include<stdio.h>
#define N 10
int S1[N],S2[N];
int top1= -1;
int top2= -1;
void push(int S[],int *top,int x)
{
    int i,a;
    if(*top==N-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        (*top)++;
        S[*top]=x;
    }
}
int pop(int S[],int *top)
{
    if(*top==-1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return S[(*top)--];
    }
}
void display(int S[],int top)
{
    int i;
    if(top==-1)
    {
        printf("\n Stack is EMPTY\n");
    }
    else
    {
        printf("\n elements in the stack\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\t",S[i]);
        }
    }
}
int main()
{
    int ch;
    int item;
    while(1)
    {
        printf("\n 1. push to stack1\n 2. pop S1 & push S2\n 3. display S1\n 4. display S2\n 0.exit\n");
        printf("\n enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\n Enter the data :");
                scanf("%d",&item);
                push(S1,&top1,item);
                break;
            }
            case 2:
            {
                item=pop(S1,&top1);
                if(item !=1)
                {
                    push(S2,&top2,item);
                    printf("Popped %d from Stack 1 and pushed to stack 2\n",item);
                }
                break;
            }
            case 3:
            {
                display(S1,top1);
                break;
            }
            case 4:
            {
                display(S2,top2);
                break;
            }
            case 0:
            {
                return 0;
                break;
            }
            default:
            printf("Invalid choice.\n");
            break;
        }
    }
}