
                    //BINARY SEARCH TREE (BST)


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
        }
        else
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
                    }
                    else
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
int main()
{
    int n;
    printf("How Many numbers :");
    scanf("%d", &n);
    createbst(n);
    printf("\n preorder traversal\n");
    preorder(root);
    return 0;
}
