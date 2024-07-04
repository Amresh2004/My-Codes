#include <stdio.h>
#define max 10

int AM[max][max], n; // n=nodes, AM=Adjacency Matrix

void BFS(int s_n) //s_n=start_node
{
    int queue[max], front = -1, rear = -1; // Queue for BFS
    int visited[max] = {0}; // Visited array to keep track of visited nodes

    queue[++rear] = s_n; // Enqueue the starting node
    visited[s_n] = 1; // Mark the starting node as visited

    while (front != rear)
    {
        int current_node = queue[++front]; // Dequeue a node
        printf("\tv%d", current_node + 1); // Print the node

        for (int n_n = 0; n_n < n; n_n++)
        {
            if (AM[current_node][n_n] == 1 && visited[n_n] == 0)
            {
                queue[++rear] = n_n; // Enqueue adjacent unvisited nodes
                visited[n_n] = 1; // Mark the node as visited
            }
        }
    }
}

int main()
{
    int i, j;
    printf("\n How many Node in a Graph : ");
    scanf("%d", &n);

    printf("\nEnter Graph : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            AM[i][j] = 0;
            printf("Is there an edge from v %d to v %d? (YES-1, NO-0) : ", i + 1, j + 1);
            scanf("%d", &AM[i][j]);
        }
    }

    printf("\n Adjacency Matrix :) \n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("\t%d", AM[i][j]);
        }
    }

    printf("\n Graph Traversal Using BFS :) \n");
    BFS(0);

    return 0;
}