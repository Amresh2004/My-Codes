#include<stdio.h>
#include<string.h>
struct job
{
	char name[20];
	int at,bt,ct,tat,wt,st,tbt;
}job[10];
int n,i,j,tq;
float avg_tat=0; 
float avg_wt=0;
// to accept the info about processes
void take_input()
{
	printf("Enter the no of jobs : ");
	scanf("%d",&n);
	printf("Enter the time Quantum: ");
	scanf("%d",&tq);
	for(i=0;i<n;i++)
	{
		printf("Enter the name of the job: ");
		scanf("%s",&job[i].name);
		printf("Enter the arrival time of the job : ");
		scanf("%d",&job[i].at);
		printf("Enter the burst time of the job: ");
		scanf("%d",&job[i].bt);
		job[i].tbt=job[i].bt;
		printf("\n\n");
	}
}
// to sort the processes by arriaval time
void sort()
{
	struct job temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(job[i].at>job[j].at)
			{
				temp=job[i];
				job[i]=job[j];
				job[j]=temp;
			}
		}
	}
}
// to calculate the tat n wt
void process()
{
	int jno=0,cnt=0,time=job[0].at;
	printf("\n***********Gantt chart*********\n");
	while(1)
	{
		if(job[jno].tbt!=0)
		{
			printf("|%d %s ",time,job[jno].name);
			if(job[jno].tbt>=tq)
			{
				job[jno].tbt=job[jno].tbt-tq;
				time=time+tq;
			}
			else
			{
				time=time+job[jno].tbt;
				job[jno].tbt=0;
			}
			printf("%d |",time);
			if(job[jno].tbt==0)
			{
				job[jno].ct=time;
				job[jno].tat=time-job[jno].at;
				job[jno].wt=job[jno].tat-job[jno].bt;
				cnt++;
			}
		}
		jno++;
		if(jno==n)
		{
			jno=0;
		}
		if(cnt==n)
			break;
	}
}
//to print the output table
void print_output()
{
	printf("\n\n");
	printf("\n---------------------------------------");
	printf("\n pname at bt tat wt ");
	printf("\n---------------------------------------");
	for(i=0;i<n;i++)
	{
		printf("\n%s %d %d %d %d ",job[i].name,job[i].at,job[i].bt,job[i].tat,job[i].wt);
		avg_tat=avg_tat+(float)(job[i].tat);
		avg_wt=(float)avg_wt+(float)(job[i].wt);
	}
	printf("\n-----------------------------------------");
	printf("\nThe avg of the turn around time is %f",avg_tat/n);
	printf("\nThe avg of the waiting time is %f",avg_wt/n);
}

int main()
{
	take_input();
	sort();
	process();
	print_output();

}
