#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *newNode, *temp, *root;

// Function to create a new node with a given key
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create BST using a loop
struct Node *createBST()
{
    root = NULL;
    int n, data;
    printf("\nEnter how many nodes: ");
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
                /*else
                {
                    // Handling insertion of same number
                    printf("\nNode with valude %d already exists.", temp->data);
                    printf("\nDo you want to go left (L&l) or right (R&r)?");
                    char ip;
                    scanf("%c", &ip);
                    if (ip == 'L' || ip == 'l')
                    {
                        temp = temp->left;
                        printf("\t%d inserted left of %d", data, temp->data);
                        break;

                    }
                    else if (ip == 'R' || ip == 'r')
                    {
                        temp = temp->right;
                        printf("\t%d inserted right of %d", data, temp->data);
                        break;
                    }
                }*/
            }
        }
    }
    return root;
}

// Function for copy
struct Node *copyBST(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        struct Node *copyNode = createNode(root->data);
        copyNode->left = copyBST(root->left);
        copyNode->right = copyBST(root->right);
        return copyNode;
    }
}

// Function for mirror
struct Node *mirror(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        struct Node *mirrorNode = createNode(root->data);
        mirrorNode->left = mirror(root->right);
        mirrorNode->right = mirror(root->left);
        return mirrorNode;
    }
}

// Function to delete a node from BST non-recursively
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

// Function to delete a node from BST recursively
struct Node *rec_DeleteBST(struct Node *root, int n)
{
    struct Node *temp, *succ;

    if (root == NULL)
    {
        printf("\nNumber not found.");
        return root;
    }

    if (n < root->data)
    { // Deleted from the left subtree
        root->left = rec_DeleteBST(root->left, n);
    }
    else if (n > root->data)
    { // Deleted from the right subtree
        root->right = rec_DeleteBST(root->right, n);
    }
    else
    { // Number to be deleted is found
        if (root->left != NULL && root->right != NULL)
        { // Node has two children
            succ = root->right;
            while (succ->left)
            {
                succ = succ->left;
            }
            root->data = succ->data;
            root->right = rec_DeleteBST(root->right, succ->data);
        }
        else
        { // Node has one or no child
            struct Node *temp = root;
            if (root->left != NULL)
            { // Only left child
                root = root->left;
            }
            else if (root->right != NULL)
            { // Only right child
                root = root->right;
            }
            else
            { // No child
                root = NULL;
            }
            free(temp);
        }
    }
    return root;
}

// Function to insert a key into the BST
struct Node *insert(struct Node *root, int key)
{
    struct Node *temp = root;
    if (temp == NULL)
    {
        return createNode(key);
    }
    if (key < temp->data)
    {
        printf("\n\t%d inserted left of %d\n", key, temp->data);
        temp->left = insert(temp->left, key);
    }
    else if (key > temp->data)
    {
        printf("\n\t%d inserted right of %d\n", key, temp->data);
        temp->right = insert(temp->right, key);
    }
    return root;
}

// Function to perform inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform preorder traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to compare two BSTs
int compareBST(struct Node *root1, struct Node *root2)
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
        int left = compareBST(root1->left, root2->left);
        int right = compareBST(root1->right, root2->right);
        int RT = (root1->data == root2->data);

        return RT && left && right;
    }
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

// Function for Odd sum
int oddsum(struct Node *root)
{
    int sum = 0;
    if (root != NULL)
    {
        if (root->data % 2 == 1)
        {
            sum = sum + root->data;
        }
        sum += oddsum(root->left);
        sum += oddsum(root->right);
    }
    return sum;
}

// Function for Even sum
int evensum(struct Node *root)
{
    int sum = 0;
    if (root != NULL)
    {
        if (root->data % 2 == 0)
        {
            sum = sum + root->data;
        }
        sum = sum + evensum(root->left);
        sum = sum + evensum(root->right);
    }
    return sum;
}

// Function to search for a key in the BST and display its level
int search(struct Node *root, int key, int level)
{
    if (root == NULL)
    {
        return -1; // Key not found
    }
    if (root->data == key)
    {
        return level; // Return the level when key is found
    }
    if (key < root->data)
    {
        return search(root->left, key, level + 1); // Traverse left subtree
    }
    return search(root->right, key, level + 1); // Traverse right subtree
}

// Function to display the menu
void displayMenu()
{
    printf("\n--------------------------------------------");
    printf("\nCREATED BY MG");
    printf("\n1. Create.");
    printf("\n2. Inorder Traversal.");
    printf("\n3. Preorder Traversal.");
    printf("\n4. Postorder Traversal.");
    printf("\n5. Copy the BST.");
    printf("\n6. Mirror the BST.");
    printf("\n7. Compare the BSTs.");
    printf("\n8. Delete BST node (Non-recursive).");
    printf("\n9. Insert a key into the BST.");
    printf("\n10. Count the nodes of tree.");
    printf("\n11. Count the leaf nodes of tree.");
    printf("\n12. Sum of Odd No.");
    printf("\n13. Sum of Even No.");
    printf("\n14. Search the node.");
    printf("\n0. Exit.");
    printf("\n--------------------------------------------");
    printf("\nEnter your choice: ");
}

int main()
{
    struct Node *root = NULL, *root1 = NULL, *root2 = NULL;
    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = createBST();
            break;

        case 2:
            printf("\nInorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("\nPreorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("\nPostorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("\nCopying BST....\n");
            struct Node *copyroot = copyBST(root);
            printf("BST copied successfully\n");
            printf("\nCopied Inorder: ");
            inorder(copyroot);
            printf("\nCopied preorder: ");
            preorder(copyroot);
            printf("\nCopied postorder: ");
            postorder(copyroot);
            break;

        case 6:
            printf("\nCreating mirror of BST....\n");
            struct Node *mroot = mirror(root);
            printf("Mirror BST created successfully\n");
            printf("\nMirror Inorder: ");
            inorder(mroot);
            printf("\nCopied preorder: ");
            preorder(mroot);
            printf("\nCopied postorder: ");
            postorder(mroot);
            break;

        case 7:
            printf("\nCreate the BSTs for compare\n");
            printf("\nFor BST1:\n");
            root1 = createBST();
            printf("\n");
            printf("\nFor BST2:\n");
            root2 = createBST();

            if (compareBST(root1, root2))
            {
                printf("\n\nBSTs are identical.\n");
            }
            else
            {
                printf("\n\nBSTs are not identical.\n");
            }
            break;

        case 8:
            if (root != NULL)
            {
                int n;
                printf("\nEnter the node to delete: ");
                scanf("%d", &n);
                root = non_rec_DeleteBST(root, n);
            }
            else
            {
                printf("Tree is empty.\n");
            }
            break;

        case 9:
            printf("\nEnter key to insert: ");
            int key;
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 10:
            printf("\nTotal Nodes: %d \n", count(root));
            break;

        case 11:
            printf("\nTotal Leaf Nodes: %d \n", countLeaf(root));
            break;

        case 12:
            printf("\nSum of Odd Numbers: %d\n", oddsum(root));
            break;
        case 13:
            printf("\nSum of Even Numbers: %d\n", evensum(root));
            break;

        case 14:
            printf("Enter key to search: ");
            scanf("%d", &key);
            int level = search(root, key, 1);
            if (level != -1)
                printf("Key %d found in the BST at level %d.\n", key, level);
            else
                printf("Key %d not found in the BST.\n", key);
            break;

        case 0:
            printf("\n\nExiting program.\n\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}