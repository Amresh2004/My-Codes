#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data); // Create new node if root is NULL
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data); // Recursively insert into left subtree
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data); // Recursively insert into right subtree
    }

    return root;
}

// Function to create a BST based on user input
struct Node *createBST()
{
    struct Node *root = NULL;
    int n, data;

    printf("\nEnter how many nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter data %d: ", i + 1);
        scanf("%d", &data);

        root = insert(root, data); // Insert node into the BST
    }

    return root;
}

// Function for count the node
int count(struct Node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    return 1 + count(temp->left) + count(temp->right);
}

// Function for count the leaf node
int countLeaf(struct Node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        return 1; // Node is a leaf
    }
    return countLeaf(temp->left) + countLeaf(temp->right);
}

// Main function to interact with the BST
int main()
{
    struct Node *root = NULL;
    int choice;

    while (choice)
    {
        printf("\n--------------------------------------------");
        printf("\n1. Create BST");
        printf("\n2. Count the nodes of tree");
        printf("\n3. Count the leaf nodes of tree");
        printf("\n4. Exit");
        printf("\n--------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = createBST();
            break;

        case 2:
            printf("\nTotal Nodes: %d \n", count(root));
            break;

        case 3:
            printf("\nTotal Leaf Nodes: %d \n", countLeaf(root));
            break;

        case 4:
            printf("\nExiting program.\n");
            return 0;
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}