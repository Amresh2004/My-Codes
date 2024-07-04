#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*head,*temp;
struct node *C_N(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    return newnode;
}
struct node *LL()
{
    int i,n,data;
    head=0;
    printf("\nEnter the size of the LL:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=C_N(data);
        printf("\nEnter the data:");
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
struct node *delete_at_start()
{
    temp=head;
    head=head->next;
    free(temp);
    return head;
}
void D()
{
    temp=head;
    do
    {
       printf("%d->",temp->data);
       temp=temp->next;
    } while (temp!=0);
    printf("NULL\n");
}
int main()
{
    int x;
    while(1)
    {
    printf("\n1.LL\n2.display\n3.delete at first\n0.exit\n");
    printf("Enter your choice:");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
               head=LL();
               break;
        case 2:
               D();
               break;
        case 3:
               delete_at_start();
               break;
        case 0:
               return 0;
               break;
        default:
                printf("Invalid chooce.\n");
                break;                            
               
    }
}
}
