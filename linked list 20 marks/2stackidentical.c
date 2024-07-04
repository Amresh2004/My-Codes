#include<stdio.h>
#define N 50
int stack1[N];
int stack2[N];
int top1=-1;
int top2=-1;
void push(int stack[],int *top,int x)
{
    int i,a;
    if(*top==N-1)
    {
        printf("stack is full\n");
    }
    else
    {
        printf("\nEnter the size of stack \n");
        scanf("%d",&a);
        for(i=0;i<a;i++)
        {
            printf("\nEnter the elements to push %d: ",i+1);
            scanf("%d",&x);
            (*top)++;
            stack[*top]=x;
        }
    }
}
void display(int stack[],int top)
{
    int i;
    if(top==-1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\n********** ELEMENTS IN STACK **********\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}
void arestackidentical(int top1,int top2)
{
  int i;
  for(i=0;i<=top1;i++)
  {
    if(stack1[i] != stack2[i])
    {
        printf("\nthe content of stack 1 and stack 2 are not identical\n");
        break;
    }
  }
  if(i==top1+1)
  {
    printf("\nthe conyent of satack 1 and stack 2 afe identical\n");
  }
}
int main()
{
  int ch,x;
  while(1)
  {
    printf("\n 1.push in stack 1\n2. push in stack 2\n3. display satack 1\n4. display stack 2\n5. check identical\n0. exit\n");
    printf("\n enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
               push(stack1,&top1,x);
               break;
        case 2:
               push(stack2,&top2,x);
               break;
        case 3:
               printf("\nStack 1:\n");
               display(stack1,top1);
               break;
        case 4:
               printf("\nStack 2:\n");
               display(stack2,top2);
               break;
        case 5:
               arestackidentical(top1,top2);
               break;
        case 0:
               return 0;
               break;
        default:
                printf("invalid choice.\n");
                break;                                         
    }
  }
}