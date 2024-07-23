#include<stdio.h>
#include<stdlib.h>
struct BSTNODE
{
    int data;
    struct BSTNODE *left;
    struct BSTNODE *right;
};
struct BSTNODE *newnode,*temp,*root;
struct BSTNODE *createBST()
{
    char ans;
    do
    {
        newnode=(struct BSTNODE *)malloc(sizeof(struct BSTNODE));
        printf("\n Enter the element to be inserted:");
        scanf("%d",&newnode->data);
        newnode->left=newnode->right=NULL;
        if(root==NULL)
        {
            root=newnode;
        }
        else
        {
            temp=root;
            while(temp!=NULL)
            {
                if(newnode->data < temp->data)
                 {
                    if(temp->left==NULL)
                    {
                        temp->left=newnode;
                        break;
                    }
                    else
                    {
                        temp=temp->left;
                    }
                 }
                 else if (newnode->data > temp->data)
                 {
                    if(temp->right==NULL)
                    {
                        temp->right=newnode;
                        break;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                 }
            }
        }
        printf("\n Do you want add more number?:");
        scanf("\n%c",&ans);
    } while (ans=='Y' || ans=='y');
}

void display(struct BSTNODE *t)
{
    if(t!=NULL)
    {
        display(t->left);
        printf("%d\t",t->data);
        display(t->right);
    }
}

int main()
{
    createBST();
    display(root);
}