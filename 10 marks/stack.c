#include<stdio.h>
#include<stdlib.h>
int top=-1;
int N=0;
int main()
{
    init();
    size();
    int stack[N];
    int ch;
    printf("\n1.Push 2.Display\n 3.Pop\n 4.Peek\n 5.IsEmpty\n 6.Isfull\n 0.Exit\n");
    while(1)
    {
        printf("\n Enter the choice\n");;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   push(stack,N);
                   break;
            case 2:
                   display(stack);
                   break;
            case 3:
                   pop(stack,N);
                   break;
            case 4:
                   peek(stack,N);
                   break;
            case 5:
                   isempty(stack,N);
                   break;
            case 6:
                   isfull(stack,N);
                   break;
            case 0:
                   return 0;
                   break;
             Default:
                     printf("Invalud choice");
                     break;                                            
        }
    }
}
void init()
{
    top = -1;
    N = 0;
}
void size()
{
    printf("Enter the size of stack:-");
    scanf("%d",&N);
}        
void push(int stack[],int N)
{
    int a,x,i;
    if(top==N-1)
    {
        printf("\nStack is Full\n");
    }
    else
    {
        printf("Enetr the size of stack");
        scanf("%d",&a);
        for(i=0;i<a;i++)
        {
            printf("Enter the elements to push",i+1);
            scanf("%d",&x);
            top=top+1;
            stack[top]=x;
        }
    }
}
void pop(int stack[],int N)
{
    if(top==-1)
    {
       printf("Stack is empty");
    }
    else
    {
        printf("Deleted eleemnts is %d\n",stack[top]);
        top=top-1;
    }
}
void peek(int stack[],int N)
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Top is %d",stack[top]);
    }
}
void isempty(int stack[],int N)
{
    if(top==-1)
    {
        printf("Stack is empty");
        return 0;
    }
    else
    {
        return 1;
    }
}
void isfull(int stack[],int N)
{
    if(top==N-1)
    {
        printf("Stack is Full");
        return 0;
    }
    else
    {
        return 1;
    }
}
void display(int stack[])
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Elements in stack");
        for(i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }
}