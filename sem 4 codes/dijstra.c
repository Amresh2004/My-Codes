#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
int visited[MAX_VERTICES];
int n; 

void dijkstra(int start) 
{
    int i, j, min_dist, next_node;
    for (i = 0; i < n; i++) 
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[start] = 0;
    for (i = 0; i < n - 1; i++) 
    {
        min_dist = INT_MAX;
        for (j = 0; j < n; j++) 
        {
            if (!visited[j] && distance[j] < min_dist) 
            {
                min_dist = distance[j];
                next_node = j;
            }
        }
        visited[next_node] = 1;
        for (j = 0; j < n; j++) 
        {
            if (!visited[j] && graph[next_node][j] && distance[next_node] + graph[next_node][j] < distance[j]) 
            {
                distance[j] = distance[next_node] + graph[next_node][j];
            }
        }
    }
}

int main() 
{
    int i, j, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    dijkstra(start);
    printf("Shortest distances from the starting vertex:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d -> %d: %d\n", start, i, distance[i]);
    }
    return 0;
}