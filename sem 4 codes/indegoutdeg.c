#include <stdio.h>
#define max 10
void ComputeDegree(int a[][max], int n)
{
    int i, j, incount, outcount;
    for (i = 0; i < n; i++)
    {
        incount = 0;
        outcount = 0;
        for (j = 0; j < n; j++)
        {
            incount += a[j][i];  
            outcount += a[i][j]; 
        }
        printf("\n Vertex = v%d\t Indegree = %d\t Outdegree = %d", i + 1, incount, outcount);
    }
}
int main()
{
    int AM[max][max], n, i, j;
    printf("\n How many Node in a Graph : ");
    scanf("%d", &n);
    printf("\n Enter Graph : ");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            AM[i][j] = 0;
            printf("Is there an edge from v %d to v %d (YES-1,NO-0):",i+1,j+1);
            scanf("%d", &AM[i][j]);
        }
    printf("\n Adjacency Matrix is as follows : \n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("\t%d", AM[i][j]);
    }
    ComputeDegree(AM, n);
    return 0;
}
