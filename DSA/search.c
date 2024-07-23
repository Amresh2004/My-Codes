#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

#define NEWNODE (struct Node *)malloc(sizeof(struct Node))

struct Node *root = NULL;

struct Node *insert(struct Node *root, int num) 
{
    if (root == NULL) 
    {
        struct Node *newNode = NEWNODE;
        newNode->data = num;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (num < root->data) 
    {
        root->left = insert(root->left, num);
    } 
    else if (num > root->data) 
    {
        root->right = insert(root->right, num);
    } 
    else 
    {
        printf("Duplicate values are not allowed in BST\n");
    }
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

int search(struct Node *root, int num, int level)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == num)
    {
        return level;
    }
    if (num < root->data)
    {
        return search(root->left, num, level + 1);
    }
    return search(root->right, num, level + 1);
}

int main()
{
    int n, num, key, level;
    printf("How many elements: ");
    scanf("%d", &n);

    printf("Enter the tree data:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Enter node data: ");
        scanf("%d", &num);
        root = insert(root, num);
    }

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Enter the key to search: ");
    scanf("%d", &key);
    level = search(root, key, 1);
    if (level != -1)
    {
        printf("Key found at level %d\n", level);
    }
    else
    {
        printf("Key not found.\n");
    }

    return 0;
}
