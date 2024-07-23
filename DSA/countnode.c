#include<Stdio.h>
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

void Inorder(struct node *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d\t",root->data);
        Inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

int countnode(struct node *root)
{
    static int count=0;
    if(root!=NULL)
    {
        count++;
        countnode(root->left);
        countnode(root->right);
    }
    return count;
}

int lcountnode(struct node *root)
{
    static int count=0;
    if(root!=NULL)
    {
        if(root->left==NULL && root->right==NULL)
        {
            count++;
        }
        lcountnode(root->left);
        lcountnode(root->right);
    }
    return count;
}

int nlcountnode(struct node *root)
{
    static int nlcount=0;
    if(root!=NULL)
    {
        if(root->left!=NULL || root->right!=NULL)
        {
            nlcount++;
            nlcountnode(root->left);
            nlcountnode(root->right);
        }
    }
    return nlcount;
}


int main()
{
    int n;
    printf("\n How many nodes:");
    scanf("%d",&n);
    createbst(n);
    printf("\n preorder transversal:");
    preorder(root);
    printf("\n inorder transversal:");
    Inorder(root);
    printf("\n postorder transversal:");
    postorder(root);
    printf("\n no.of nodes:%d",countnode(root));
    printf("\n no.of leaf nodes:%d",lcountnode(root));
    printf("\n no.of non leaf nodes:%d",nlcountnode(root));
}