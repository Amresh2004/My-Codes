#include <stdio.h>
#define max 10

int AM[max][max], n; 

void recursive_DFS(int s_n) 
{
    int n_n; 
    static int visited[max] = {0}; 

    visited[s_n] = 1;
    printf("\tv%d", s_n + 1);

    for (n_n = 0; n_n < n; n_n++)
    {
        if (AM[s_n][n_n] == 1 && visited[n_n] == 0)
        {
            recursive_DFS(n_n);
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
            printf("there an edge from v %d to v %d (YES-1, NO-0) : ", i + 1, j + 1);
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

    printf("\n Graph Traversal Using DFS :) \n");
    recursive_DFS(0);

    return 0;
}