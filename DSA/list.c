#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;//vertices
    struct node *next;//edge
};

// Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a list
void createList(struct node *list[], int n)
{
    int i, j, ans;
    struct node *temp, *last;
    printf("\nEnter Graph:\n");
    for (i = 0; i < n; i++)
    {
        list[i] = NULL;
        last=NULL;
        for (j = 0; j < n; j++)
        {
                printf("Is there an edge between %d and %d vertices? (yes-1, No-0): ", i + 1, j + 1);
                scanf("%d", &ans);
                if (ans == 1)
                {
                    temp = createNode(j);
                    if (list[i] == NULL)
                    {
                        list[i] = temp;
                        last = temp;
                    }
                    else
                    {
                        last->next = temp;
                        last = temp;
                    }
                }
        }
    }
}

// Function to display the list
void displayList(struct node *list[], int n)
{
    struct node *temp;
    int i;
    printf("\nAdjacency list:\n");
    for (i = 0; i < n; i++)
    {
        printf("v%d", i + 1);
        temp = list[i];
        while (temp != NULL)
        {
            printf("\t%d", temp->data + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("How many vertices: ");
    scanf("%d", &n);
    struct node *list[n];
    createList(list, n);
    displayList(list, n);
    return 0;
}