#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

#define NEWNODE (struct node *)malloc(sizeof(struct node))
struct node *root = NULL;

struct node* insert(struct node* root, int num) 
{
    if (root == NULL) 
    {
        struct node* newNode = NEWNODE;
        newNode->data = num;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (num < root->data) 
    {
        root->left = insert(root->left, num);
    } 
    else if (num > root->data) 
    {
        root->right = insert(root->right, num);
    } 
    else 
    {
        printf("Duplicate values are not allowed in BST\n");
        return root;
    }
    return root;
}

void createbst(int n) 
{
    int i, num;
    printf("Enter the Tree data\n");
    for (i = 0; i < n; i++) 
    {
        printf("Enter Node data\n");
        scanf("%d", &num);
        root = insert(root, num);
    }
}

void preorder(struct node *root) 
{
    if (root != NULL) 
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() 
{
    int n,choice,num;
    while(1)
    {
        printf("\n\t\t\tBINARY SEARCH TREE\n");
        printf("1-Create\n");
        printf("2-Insert\n");
        printf("3-Display\n");
        printf("4-Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   printf("How many nodes in tree\n");
                   scanf("%d",&n);
                   createbst(n);
                   break;
            case 2:
                   printf("Enter the number to be inserted\n");
                   scanf("%d",&num);
                   root=insert(root,num);
                   break; 
            case 3:
                   printf("preorder trasnversal\n");
                   preorder(root);
                   break;
            case 4:
                   printf("exit");
                   break;
            default:
                    printf("invalid choice");
                    break;                          
        }
    }
} 