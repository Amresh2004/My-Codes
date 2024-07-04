#include<stdio.h>
#include<stdlib.h>
int top=-1;
int N=0;
void size()
{
    printf("enter the size of stack:-");
    scanf("%d",&N);
}
void push(char stack[],char item)
{
    if(top==N-1)
    {
        printf("Stack is full");
    }
    else
    {
        top=top+1;
        stack[top]=item;
    }
}
char pop(char stack[])
{
    if(top==-1)
    {
        return '\0';
    }
    char item=stack[top];
    top=top-1;
    return item;
}
void reversestring(char *str)
{
    int len =strlen(str);
    char stack[len];
    top=-1;
    for(int i=0;i<len;i++)
    {
        push(stack,str[i]);
    }
    for(int i=0;i<len;i++)
    {
        str[i]=pop(stack);
    }
}
int main()
{
    size();
    char input[100];
    printf("Enter a string:-");
    scanf("%s",input);
    reversestring(input);
    printf("Reversed string:%s\n",input);
    return 0;
}