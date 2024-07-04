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

void createbst(int n) 
{
    int i, num;
    struct node *t, *p;
    printf("Enter the Tree data\n");
    for (i = 0; i < n; i++) 
    {
        printf("Enter Node data\n");
        scanf("%d", &num);
        p = NEWNODE;
        p->data = num;
        p->left = NULL;
        p->right = NULL;
        if (root == NULL) 
        {
            root = p;
        } else 
        {
            t = root;
            while (1) 
            {
                if (num > t->data) 
                {
                    if (t->right == NULL) 
                    {
                        t->right = p;
                        break;
                    } else 
                    {
                        t = t->right;
                    }
                } 
                else if (num < t->data) 
                {
                    if (t->left == NULL) 
                    {
                        t->left = p;
                        break;
                    } 
                    else 
                    {
                        t = t->left;
                    }
                } 
                else 
                {
                    printf("Duplicate values are not allowed in BST\n");
                    free(p);
                    return;
                }
            }
        }
    }
}

void preorder(struct node *t) 
{
    if (t != NULL) 
    {
        printf("%d\t", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(struct node *t) 
{
    if (t != NULL) 
    {
        inorder(t->left);
        printf("%d\t", t->data);
        inorder(t->right);
    }
}

void postorder(struct node *t) 
{
    if (t != NULL) 
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d\t", t->data);
    }
}

int main() 
{
    int n, choice;
    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Create BST\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("How many numbers? ");
                scanf("%d", &n);
                createbst(n);
                break;
            case 2:
                printf("\nPreorder Traversal:\n");
                preorder(root);
                break;
            case 3:
                printf("\nInorder Traversal:\n");
                inorder(root);
                break;
            case 4:
                printf("\nPostorder Traversal:\n");
                postorder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}