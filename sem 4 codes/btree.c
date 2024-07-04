#include<stdio.h>
#include<stdlib.h>

struct node 
{
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

void display(struct node *temp) 
{
    if (temp) 
    {
        printf("%d\t", temp->data);
        display(temp->left);
        display(temp->right);
    }
}

int search(struct node *temp, int data) 
{
    if (temp == NULL)
    {
        return 0;
    } 
    if (temp->data == data) 
    {
        printf("Data found");
        return 1; 
    }
    return search(temp->left, data) || search(temp->right, data);
}

void inorder(struct node *temp) 
{
    if (temp) 
    {
        inorder(temp->left);
        printf("%d\t", temp->data);
        inorder(temp->right);
    }
}

void preorder(struct node *temp) 
{
    if (temp) 
    {
        printf("%d\t", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct node *temp) 
{
    if (temp) 
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t", temp->data);
    }
}

int menu() 
{
    int ch;
    system("clear");
    printf("\n\t1.Create\n\t2.Insert\n\t3.Search\n\t4.Display\n\t5.Inorder\n\t6.Preorder\n\t7.Postorder\n\t0.Exit\n\tEnter your choice: ");
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
            {
                int node;
                printf("\nEnter data: ");
                scanf("%d", &node);
                insert(&root, node);
                break;
            }
            case 3: 
            {
                int node;
                printf("\nEnter node to be searched: ");
                scanf("%d", &node);
                if (!search(root, node))
                {
                    printf("Data not found");
                }
                getchar(); 
                getchar(); 
                break;
            }
            case 4:
                display(root);
                getchar();
                getchar();
                break;
            case 5:
                printf("\nInorder Traversal: ");
                inorder(root);
                getchar();
                getchar();
                break;
            case 6:
                printf("\nPreorder Traversal: ");
                preorder(root);
                getchar();
                getchar();
                break;
            case 7:
                printf("\nPostorder Traversal: ");
                postorder(root);
                getchar();
                getchar();
                break;
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}