#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node *head,*temp,*newnode,*last;

struct node* create_node(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    return newnode;
}





struct node* SLL()
{
    int i,n,data;
    head=0;
    printf("Enter the size of LL: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=create_node(data);
        printf("Enter data %d : ",i+1);
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
    while(temp!=0)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}


void reverse(struct node*head)
{
    if(head==0)
    return;
    reverse(head->next); 
    printf("<-%d",head->data);
}



int main()
{
    int ch;
    while(1)
    {
        printf("\n1.LL \n2.Display \n3.reverse \n0.Exit \n\nEnter the choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                head=SLL();
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3: 
            {
                reverse(head);
               
                break;
            }
            case 0:
            {
                return 0;
            }
            default:printf("INVALID CHOICE");
            break;
        }
    }
}