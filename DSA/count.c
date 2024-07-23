#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *createnode(int data) 
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void insert(struct node **root, int data) 
{
    if (*root == NULL)
    {
        *root = createnode(data);
    } 
    else if (data <= (*root)->data) 
    {
        insert(&((*root)->left), data);
    } 
    else 
    {
        insert(&((*root)->right), data);
    }
}

void createbst(struct node **root) 
{
    int n, data;
    printf("\nEnter how many nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(root, data);
    }
}

int count(struct node *temp) 
{
    if (temp == NULL) 
    {
        return 0;
    }
    return 1 + count(temp->left) + count(temp->right);
}

int countLeaf(struct node *temp) 
{
    if (temp == NULL) 
    {
        return 0;
    }
    if (temp->left == NULL && temp->right == NULL) 
    {
        return 1; 
    }
    return countLeaf(temp->left) + countLeaf(temp->right);
}

void display(struct node *temp) 
{
    if (temp) 
    {
        display(temp->left);
        printf("%d\t", temp->data);
        display(temp->right);
    }
}

int menu() 
{
    int ch;
    system("clear");
    printf("\n\t1.Create\n\t2.Count Nodes\n\t3.Count Leaf Nodes\n\t4.Display\n\t0.Exit\n\tEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

int main() 
{
    struct node *root = NULL;
    int ch;
    while ((ch = menu()) != 0) 
    {
        switch (ch) 
        {
            case 1:
                createbst(&root);
                break;
            case 2:
                printf("\nTotal Nodes: %d", count(root));
                getchar();
                getchar();
                break;
            case 3:
                printf("\nTotal Leaf Nodes: %d", countLeaf(root));
                getchar();
                getchar();
                break;
            case 4:
                printf("\nIn-order Traversal: ");
                display(root);
                getchar();
                getchar();
                break;
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}
