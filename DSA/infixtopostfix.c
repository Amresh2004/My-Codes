#include<stdio.h>
int top=-1;
char stack[50];
int main()
{
    char infix[30];
    printf("Enter the infix string:");
    scanf("%s",infix);
    infixtopostfix(infix);
}
void push(char ch)
{
    top++;
    stack[top]=ch;
}
char pop()
{
    char c;
    c=stack[top];
    top--;
    return c;
}
char peek()
{
    char c;
    c=stack[top];
    return c;
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isOperand(char ch)
{
    if(ch>='A' && ch<='Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedance(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
                 return 1;
        case '*':
        case '/':
                 return 2;
        case '^':
                 return 3;                  
    }
    return -1;
}
void infixtopostfix(char infix[30])
{
    int i,j=0;
    char expr[30];
    for(i=0;infix[i]!='\0';i++)
    {
        if(isOperand(infix[i])==1)
        {
            expr[j++]=infix[i];
        }
        else if (infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(isEmpty()!=1 && peek()!='(')
            {
                expr[j++]=pop();
            }
        }
        else if(precedance(infix[i])> precedance(peek()))
        {
            push(infix[i]);
        }
        else if((precedance(infix[i])== precedance(peek())))
        {
            expr[j++]=pop();
            push(infix[i]);
        }
    }
    while(!isEmpty())
    {
        expr[j++]=pop();
    }
    expr[j]='\0';
    printf("%s",expr);
}