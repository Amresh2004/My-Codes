
                    //MIRROR and COPY BST


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
#define NEWNODE (struct node*)malloc(sizeof(struct node))
struct node *root=NULL;
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

struct node *mirror(struct node *root)
{
    struct node *t;
    if(root==NULL)
    {
        return;
    }
    else
    {
        t=NEWNODE;
        t->data=root->data;
        t->left=t->right=NULL;
        t->left=mirror(root->right);
        t->right=mirror(root->left);
        return t;
    }
}
struct node *copy(struct node *root)
{
    struct node *t;
    if(root==NULL)
    {
        return;
    }
    else
    {
        t=NEWNODE;
        t->data=root->data;
        t->left=t->right=NULL;
        t->left=copy(root->right);
        t->right=copy(root->left);
        return t;
    }
}

void preorder(struct node *t)
{
    if(t!=NULL)
    {
        printf("%d\n",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

int main()
{
    int n,*mirrorroot,*copyroot;
    printf("How many numbers:");
    scanf("%d",&n);
    createbst(n);
    printf("Preorder travsal\n");
    preorder(root);
    printf("\n After mirror:");
    mirrorroot=mirror(root);
    preorder(mirrorroot);
    copyroot=copy(mirrorroot);
    copyroot=copy(root);
    printf("\n after copy original BST:");
    preorder(copyroot);
    return 0;
}
