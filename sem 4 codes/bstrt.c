#include <stdio.h>
#define Max 10

int AM[Max][Max];
int i,j,n;

void BFS(int s_n)
{
    int queue[Max],front=0,rear=0;
    int visited[Max]={0};

    queue[rear++]=s_n;
    visited[s_n]=1;

    while(front < rear)
    {
        int current_node=queue[front++];
        printf("\tv%d", current_node + 1);

        for(int n_n=0;n_n<n;n_n++)
        {
            if(AM[current_node][n_n]==1 && !visited[n_n])
            {
                queue[rear++]=n_n;
                visited[n_n]=1;
            }
        }
    }
}
int main()
{
    printf("enter the number of nodes in the graph: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("is there an edge from v%d to v%d? (YES-1 NO-0):",i+1,j+1);
            scanf("%d",&AM[i][j]);
        }
    }
    printf("\n ajacency matrix:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d",AM[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    printf("\ngraph trabser:\n");
    BFS(0);

    return 0;
}