#include <stdio.h>
#include <stdlib.h>
struct Node {
    struct Node *left;
    int data;
    struct Node *right;
};
struct Node *newNode, *temp, *root;
struct Node *createNode(int data) 
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node *createBST() {
    root = NULL;
    int n, data;
    printf("Enter how many nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        printf("Enter data %d: ", i + 1);
        scanf("%d", &data);
        if (root == NULL) 
        {
            root = createNode(data);
        } else 
        {
            temp = root;
            while (temp != NULL) 
            {
                if (data < temp->data) 
                {
                    if (temp->left == NULL) 
                    {
                        temp->left = createNode(data);
                        break;
                    } else 
                    {
                        temp = temp->left;
                    }
                } 
                else if (data > temp->data) 
                {
                    if (temp->right == NULL) 
                    {
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
void Display(struct Node *root) 
{
    if (root != NULL) 
    {
        Display(root->left);
        printf("%d ", root->data);
        Display(root->right);
    }
}
void displayMenu() 
{
    printf("\n1. Create");
    printf("\n2. Display");
    printf("\n0. Exit");
    printf("\nEnter your choice: ");
}
int main() 
{
    struct Node *root = NULL;
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                root = createBST();
                break;
            case 2:
                printf("\n\n");
                Display(root);
                printf("\n");
                break;
            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}