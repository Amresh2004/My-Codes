#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) 
{
    if (root == NULL) 
    {
        return createNode(data);
    }

    if (data < root->data) 
    {
        root->left = insertNode(root->left, data);
    } 
    else if (data > root->data) 
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void displayLevelOrder(struct Node* root) 
{
    int height = treeHeight(root);
    for (int level = 1; level <= height; level++) 
    {
        printf("Level %d: ", level);
        printLevel(root, level);
        printf("\n");
    }
}

void printLevel(struct Node* root, int level) 
{
    if (root == NULL) 
    {
        return;
    }

    if (level == 1) 
    {
        printf("%d ", root->data);
    } 
    else 
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int treeHeight(struct Node* root) 
{
    if (root == NULL) 
    {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int main() 
{
    struct Node* root = NULL;
    int choice, data,height;

    do 
    {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert Node\n2. Display Nodes at Each Level\n3. Display Total Levels\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Nodes at each level:\n");
                displayLevelOrder(root);
                break;
            case 3:
                height = treeHeight(root);
                printf("Total levels in the tree: %d\n", height);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}