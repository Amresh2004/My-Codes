#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *newnode,*temp,*last,*head;
struct node *create_node(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    newnode->prev=0;
    return newnode;
}
struct node *CDLL()
{
    int i,n,data;
    printf("ENTER THE SIZE OF DOUBLY LINKED LIST\n");
    scanf("%d",&n);
    head=last=0;
    for(i=0;i<n;i++)
    {
        newnode=create_node(data);
        printf("Enter the data:");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=last=newnode;
        }
        else
        {
            newnode->prev=last;
            last->next=newnode;
            last=newnode;
        }
    }
    return head;
}
void display()
{
    temp=head;
    printf("***** DOUBLY LINKRD LIST *****\n");
    do
    {
       printf("%d<->",temp->data);
       temp=temp->next;
    } 
    while(temp !=0);
    printf("NULL\n");
}
int main()
{
   int choice=1;
   while(choice)
   {
      int userchoice;
      printf("\n LINKED LIST OPERATION\n");
      printf("1-create linked list\n");
      printf("2-Display\n");
      printf("0-exit\n");
      printf("\n");
      printf("CHOOSE AN OPERATION:-");
      scanf("%d",&userchoice);
      switch(userchoice)
      {
        case 1:
               head=CDLL();
               break;
        case 2:
               display();
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