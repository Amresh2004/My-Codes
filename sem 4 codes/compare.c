
                   //COMPARE BETWEEN 2 BST

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

struct node* createbst(int n)
{
    int i, num;
    struct node *p;
    printf("Enter Node data:\n");
    scanf("%d", &num);
    p = NEWNODE;
    p->data = num; 
    p->left = NULL;
    p->right = NULL;
    root = p;

    for (i=1;i<n;i++)
    {
        printf("Enter Node data:\n");
        scanf("%d",&num);
        p = NEWNODE;
        p->data = num;
        p->left = NULL;
        p->right = NULL;

        struct node *num = root; 
        struct node *t = NULL; 
        while (num != NULL) 
        {
          t = num;
          if (p->data > num->data)
          {
            num = num->right;
          }
          else
          {
            num = num->left;
          }
        }
       if (p->data > t->data)
       { 
         t->right = p;
       }
       else
       {
         t->left = p;
       }
    }
    return root;
}

int compare(struct node *root1, struct node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }
    else
    {
        if (root1->data == root2->data &&
            compare(root1->left, root2->left) &&
            compare(root1->right, root2->right))
        
        return 1;
    }
}

void preorder(struct node *t)
{
    if (t != NULL)
    {
        printf("%d->", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

int main()
{
    int n;
    struct node *root1, *root2;
    printf("How many nodes in first BST:\n");
    scanf("%d", &n);
    root1 = createbst(n);
    preorder(root1);
    printf("\nPreorder Transversal\n");

    printf("\nHow many nodes in second BST:\n");
    scanf("%d", &n);
    root2 = createbst(n);
    preorder(root2);
    printf("\nPreorder Transversal\n");

    if (compare(root1, root2))
    {
        printf("\nBSTs ARE SAME\n");
    }
    else
    {
        printf("\nBSTs ARE NOT SAME\n");
    }
}