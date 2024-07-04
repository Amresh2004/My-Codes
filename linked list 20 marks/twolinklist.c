#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *head, *temp;

struct node *C_N(int data)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = 0;
    return newnode;
}

struct node *LL()
{
    int i, n, data;
    head = 0;
    printf("\nEnter the size of LL:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the data:");
        scanf("%d", &data);
        newnode = C_N(data);
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void D(struct node *L)
{
    temp = L;
    while (temp != 0)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* mergelists(struct node*L1 , struct node*L2)
{
    if(L1==0)
    {
        return L2;
    }
    if(L2==0)
    {
        return L1;
    }

    if(L1->data < L2->data)
    {
        L1->next=mergelists(L1->next,L2);
        return L1;
    }
    else
    {
        L2->next=mergelists(L1,L2->next);
        return L2;
    }    
}
int main()
{
    int X;
    struct node *L1 = NULL;
    struct node *L2 = NULL;
    struct node *mergelist = NULL;

    while (1)
    {
        printf("\n1. Create Linked List 1\n2. Create Linked List 2\n3. Merge Linked List\n0. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &X);
        switch (X)
        {
        case 1:
            printf("\nCreate Linked List 1:");
            L1 = LL();
            printf("List 1:");
            D(L1);
            break;
        case 2:
            printf("\nCreate Linked List 2:");
            L2 = LL();
            printf("List 2:");
            D(L2);
            break;
        case 3:
            mergelist = mergelists(L1,L2);
            D(mergelist);
            printf("Linked List Merged Succesfully.\n");
            break;
        case 0:
            return 0;
            break;
        default:
            printf("invalid choice.\n");
            break;
        }
    }
    return 0;
}