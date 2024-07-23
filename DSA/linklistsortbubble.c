#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node *newnode, *head, *temp, *last, *tp;
struct node*create_node(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    return newnode;
}
struct node*linklist()
{
    int i, n, data;
    printf("Enter the size of singly linked list\n");
    scanf("%d",&n);
    head=0;
    for(i=0;i<n;i++)
    {
        newnode=create_node(data);
        printf("Enter the data %d:",i+1);
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}
void display()
{
    temp=head;
    while(temp !=0)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void bubblesort(struct node* head)
{
    int swapped;
    temp=NULL;
    do
    {
        swapped=0;
        tp=head;
        while(tp->next != temp)
        {
           if(tp->data > tp->next->data)
           {
              int tempdata=tp->data;
              tp->data=tp->next->data;
              tp->next->data=tempdata;
              swapped=1;
           }
           tp=tp->next;
        }
        temp=tp;
    }   while(swapped);    
}
int main()
{
    int choice=1;
    head=NULL;
    while(choice)
    {
        int userchoice;
        printf("\nLink List Operation\n");
        printf("1 - create link list\n");
        printf("2 - display\n");
        printf("3 - sort the list\n");
        printf("0 - exit\n");
        scanf("%d",&userchoice);

        switch(userchoice)
        {
            case 1:
            {
                head=linklist();
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                bubblesort(head);
                printf("list sorted using bubble sort.\n");
                display();
                break;
            }
            case 0:
            {
                return 0;
            }
            default:
                    printf("invalid choice.\n");
                    break;
        }
    }
}