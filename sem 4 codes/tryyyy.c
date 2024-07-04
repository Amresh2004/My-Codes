#include<stdio.h>

int visited[10]={0},cost[10][10],min,mincost=0;

int input(int num) 
{
    int i,j;
    printf("Enter the adjacency matrix\n");
    for(i=1; i<=num; i++) 
    {
        for(j=1; j<=num; j++) 
        {
            printf("Value of cost:[%d][%d]: ", i, j);
            scanf("%d",&cost[i][j]);
        }
    }
    return 0;
}

int display(int num) 
{
    int i,j;
    printf("The cost adjacency matrix\n");
    for(i=1; i<=num; i++) 
    {
        for(j=1; j<=num; j++) 
        {
            printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int prims(int num) 
{
    int i,j,ne=1,a,b,u,v;
    for(i=1; i<=num; i++) 
    {
        for(j=1; j<=num; j++) 
        {
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    visited[1]=1;
    while (ne<num) 
    {
        for(i=1,min=999; i<=num; i++) 
        {
            for(j=1; j<=num; j++) 
            {
                if(cost[i][j] < min) 
                {
                    if(visited[i]!=0) 
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        printf("\n Edge %d: (%d-%d) cost=%d", ne++, a, b, min);
        mincost=mincost+min;
        visited[b]=1;
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMinimum cost = %d \n", mincost);
}

int main() 
{
    int num;
    printf("How many elements: ");
    scanf("%d", &num);
    input(num);
    display(num);
    prims(num);
    return 0;
}
