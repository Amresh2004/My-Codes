#include <stdio.h>

#define Max_Node 10

int AM[Max_Node][Max_Node]; // Adjacency Matrix
int n; // Number of nodes

void BFS(int start_N)
{
    int queue[Max_Node]; // Queue for BFS
    int front = 0, rear = 0; // Queue pointers
    int visited[Max_Node] = {0}; // Visited array to keep track of visited nodes

    queue[rear++] = start_N; // Enqueue the starting node
    visited[start_N] = 1; // Mark the starting node as visited

    while (front < rear)
    {
        int temp_N = queue[front++]; // Dequeue a node
        printf("\tv%d", temp_N + 1); // Print the node

        for (int A_N = 0; A_N < n; A_N++)
        {
            if (AM[temp_N][A_N] == 1 && !visited[A_N])
            {
                queue[rear++] = A_N; // Enqueue adjacent unvisited nodes
                visited[A_N] = 1; // Mark the node as visited
            }
        }
    }
}

int main()
{
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Is there an edge from v%d to v%d? (1/0): ", i + 1, j + 1);
            scanf("%d", &AM[i][j]);
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", AM[i][j]);
        }
        printf("\n");
    }

    printf("\nGraph Traversal Using BFS starting from node v1:\n");
    BFS(0); // Start BFS traversal from node v1 (index 0)

    return 0;
}