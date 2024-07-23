#include<stdio.h>
#include<string.h>
#define N 100
int stack[N];
int top = -1;
void push(int item)
{
    if(top >= N-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top]=item;
    }
}
int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        return stack[top--];
    }
}
int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}
int E_P(char *Q)
{
    int i;
    int op1, op2;
    int result;
    for(i=0; Q[i] != '\0'; i++)
    {
        if(isDigit(Q[i]))
        {
            push(Q[i] - '0');
        }
        else
        {
            if(top < 1)
            {
                printf("Invalid Expression\n");
            }
            op2=pop();
            op1=pop();
            switch(Q[i])
            {
                case '+':
                     push(op1 + op2);
                     break;
                case '-':
                    push(op1 - op2);
                    break;     
                case '*':
                    push(op1 * op2);
                    break;
                 case '/':
                    if(op2==0)
                    {
                        printf("Division by Zero\n");
                    }
                    push(op1 - op2);
                    break;
                 default:
                    printf("Invalid charachter in expression\n");
                    break;                       
            }
        }
    }
    if(top!=0)
    {
        printf("invalid expression\n");
    }
    result=pop();
    return result;
}
int main()
{
    char Q[100];
    printf("Enter a postfix expression: ");
    scanf("%s",Q);
    int result=E_P(Q);
    printf("Result: %d\n",result);
    return 0;
}