#include<stdio.h>
int visited[10]={0}, cost[10][10], min, mincost=0;
int input(int n)
{
	int i, j;
	printf("\nEnter the adjacency matrix\n\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("value of cost[%d][%d] : ",i,j);
			scanf("%d", &cost[i][j]);
		}
	}
	return 0;
}
int display(int n)
{
	int i, j;
	printf("\nThe cost of adjacency matrix\n\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("%d", cost[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	return 0;
}
int prims(int n)
{
	int i, j, ne=1, a, b, u, v;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(cost[i][j]==0)
			cost[i][j]=999;
		}
	}
	visited[1]=1; 
	while(ne < n) 
	{
		for(i=1,min=999;i<=n;i++)
		for(j=1;j<=n;j++)
		if(cost[i][j]< min)
		if(visited[i]!=0)
		{
			min=cost[i][j];
			a=u=i; 
			b=v=j;
		}
		printf("\n Edge %d:(%d - %d) cost:%d",ne++,a,b,min);
 		mincost=mincost+min;
 		visited[b]=1;
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\n\n Minimun cost=%d",mincost);
}
int main()
{
	int n;
	printf("\n\t\t\tPrim's Algorithm");
	printf("\n\nEnter the number of nodes= ");
	scanf("%d", &n);
	input(n);
	display(n);
	prims(n);
    return 0;
}