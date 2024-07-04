
                     // DELETE BST PROGRAM


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *newNode, *temp, *root;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node *createBST()
{
    root = NULL;
    int n, data;
    printf("Enter how many nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter data %d: ", i + 1);
        scanf("%d", &data);

        if (root == NULL)
        {
            root = createNode(data);
        }
        else
        {
            temp = root;
            while (temp != NULL)
            {
                if (data < temp->data)
                {
                    if (temp->left == NULL)
                    {

                        printf("\t%d inserted left of %d", data, temp->data);

                        temp->left = createNode(data);
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else if (data > temp->data)
                {
                    if (temp->right == NULL)
                    {

                        printf("\t%d inserted right of %d", data, temp->data);

                        temp->right = createNode(data);
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    return root;
}
struct Node *non_rec_DeleteBST(struct Node *root, int n)
{
    struct Node *temp = root, *parent = NULL, *child, *succ, *parsucc;

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
void inorder(struct Node *root)
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
    int choice;
    while(1)
    {
        printf("1.create\n");
        printf("2.display\n");
        printf("3.delete\n");
        printf("eneter the choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   {
                    root = createBST();
                    break;
                   }

            case 2:
                   {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                    break;  
                   }

             case 3:
                    {
                       if (root != NULL)
                       {
                          int n;
                          printf("Enter the node to delete: ");
                          scanf("%d", &n);
                          root = non_rec_DeleteBST(root, n);
                          inorder(root);
                       }
                       else
                       {
                          printf("Tree is empty.\n");
                       }
                       break;
                    }

            default: 
                    printf("invalid choice");
                    break;      
        }
    }
    return 0;
}
