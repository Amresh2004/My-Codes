#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node *next;
};

struct node *head,*temp,*newnode;

struct node* create_node(struct node *head,int co, int ex)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=co;
    newnode->expo=ex;
    newnode->next=0;
    

    if(head==0 || ex > newnode->expo)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next != 0 && temp->next->expo >= ex)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}

struct node* poly(struct node* head)
{
    int i,n;
    int co,ex;

    printf("Enter the number of terms: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enret the coefficient for term %d: ",i+1);
        scanf("%d",&co);
        printf("Enter the exponent for term %d: ",i+1);
        scanf("%d",&ex);
        head=create_node(head,co,ex);

    }
    return head;
}

void print(struct node*head)
{
    temp=head;
    while(temp != 0)
    {
        printf("(%dx^%d)",temp->coeff,temp->expo);
        temp=temp->next;
        if(temp != 0)
        {
            printf("+");
        }
        else
        {
            printf("\n");
        }
    }
}

void MUL(struct node *head1,struct node *head2)
{
    struct node *ptr1=head1,*ptr2=head2,*head3=0;

    while(ptr1 != 0)
    {
        while(ptr2 != 0)
        {
            head3=create_node(head3,ptr1->coeff *ptr2->coeff,ptr1->expo * ptr2->expo);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
        ptr2=head2;
    }
    printf("MULTIPLY POLY : ");
    print(head3);
}


void ADD(struct node *head1,struct node *head2)
{
    struct node *ptr1=head1,*ptr2=head2,*head3=0;

    while(ptr1 != 0 && ptr2 != 0)
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3=create_node(head3,ptr1->coeff+ptr2->coeff,ptr1->expo+ptr2->expo);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3=create_node(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->next;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3=create_node(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->next;
        }
    }
    while(ptr1 != 0)
    {
        head3=create_node(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->next;
    }
    while(ptr2 != 0)
    {
        head3=create_node(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->next;
    }

    printf("ADDED POLY : ");
    print(head3);
}


int main()
{
    struct node *head1=0,*head2=0;
    printf("Enter the 1st poly\n");
    head1=poly(head1);
    printf("1st\n");
    print(head1);

    printf("Enter the 2nd poly\n");
    head2=poly(head2);
    printf("2nd\n");
    print(head2);

    printf("\nmul is\n");
    MUL(head1,head2);

    printf("\nadd is\n");
    ADD(head1,head2);

}