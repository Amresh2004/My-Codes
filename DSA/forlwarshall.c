#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES][MAX_VERTICES];
int n; 

void floyd_warshall() 
{
    int i, j, k;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            path[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < n; k++) 
    {
        for (i = 0; i < n; i++) 
        {
            for (j = 0; j < n; j++) 
            {
                if (path[i][k] != INT_MAX && path[k][j] != INT_MAX && path[i][k] + path[k][j] < path[i][j]) 
                {
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
}

int main() 
{
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) 
            {
                graph[i][j] = INT_MAX; 
            }
        }
    }
    floyd_warshall();
    printf("The shortest path matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if (path[i][j] == INT_MAX) 
            {
                printf("%7s", "INF");
            } 
            else 
            {
                printf("%7d", path[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}