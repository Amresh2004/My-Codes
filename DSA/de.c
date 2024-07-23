#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *create(struct node *root,int n)
{
    if(root==NULL)
    {
        root=(struct node *)malloc(sizeof(struct node));
        root->left=root->right=NULL;
        root->data=n;
        return root;
    }
    else
    {
        if(n< root->data)
        {
            root->left=create(root->left,n);
        }
        else if(n > root->data)
        {
            root->right=create(root->right,n);
        }
        else
        {
            printf("Duplicate elelemnts is not allowed");
        }
        return root;
    }
}

struct node *non_rec_DeleteBST(struct Node *root, int n)
{
    struct node *temp = root, *parent = NULL, *child, *succ, *parsucc;

    while (temp != NULL)
    {
        if (n == temp->data)
        {
            break;
        }
        parent = temp;
        if (n < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp == NULL)
    {
        printf("Number not found.\n");
        return root;
    }

    if (temp->left != NULL && temp->right != NULL)
    {
        parsucc = temp;
        succ = temp->right;
        while (succ->left != NULL)
        {
            parsucc = succ;
            succ = succ->left;
        }
        temp->data = succ->data;
        temp = succ;
        parent = parsucc;
    }

    if (temp->left != NULL)
    {
        child = temp->left;
    }
    else
    {
        child = temp->right;
    }

    if (parent == NULL)
    {
        root = child;
    }
    else if (temp == parent->left)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }

    free(temp);
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    int n,item,root,choice;
    while(1)
    {
        printf("1.create\n");
        printf("2.display\n");
        printf("3.delete\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   create(root,item);
                   break;

             case 2:
                    inorder(root);
                    break;

              case 3:
                     non_rec_DeleteBST(root,n);
                     break;

              default:
                      printf("inavlid choice");

        }
    }
}