#include<stdio.h>
#include<string.h>
struct job
{
	char name[20];
	int at,bt,ct,tat,wt,st,tbt,p;
}job[10];
int jno,n,i,j;
float avg_tat=0;
float avg_wt=0;

void take_input()
{
	printf("Enter the no of jobs : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the name of the job: ");
		scanf("%s",job[i].name);
		printf("Enter the arrival time of the job: ");
		scanf("%d",&job[i].at);
		printf("Enter the burst time of the job:");
		scanf("%d",&job[i].bt);
		printf("Enter the priority: ");
		scanf("%d",&job[i].p);
		job[i].tbt=job[i].bt;
		printf("\n\n");
	}
}
void process()
{
	int time=0,cnt=0,i;
	char prev_job[10],cur_job[10];
	while(1)
	{
		jno=getjob(time);
		job[jno].tbt--;
		strcpy(cur_job,job[jno].name);
		if(strcmp(cur_job,prev_job)!=0)
			printf("%d --> %s",time,job[jno].name);
		time++;
		if(job[jno].tbt==0)
		{
			job[jno].ct=time;
			job[jno].tat=time-job[jno].at;
			job[jno].wt=job[jno].tat-job[jno].bt;

			cnt++;
		}
		strcpy(prev_job,cur_job);
		if(cnt==n)
			break;
	} 
	printf("End Time %d",time);
}

int getjob(int time)
{
	int i,min=0,k;
	for(i=0;i<n;i++)
		if(job[i].at<=time && job[i].tbt!=0)
		{
			if(min<job[i].p)
			{
				min=job[i].p;
				k=i;
			}
		}
	return k;
}
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
	process();
	print_output();
	for(i=0;i<n;i++)
	{
		job[i].tbt=job[i].bt=rand()%10+1;
		job[i].at=job[i].ct+2;
	}

}
