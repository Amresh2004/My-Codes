

#include<stdio.h>
#include<string.h>
struct job 
{
	char name[20];
	int at, bt, ct, tat, wt, st, tbt;
	
} 
job[10];

int n, i, j;
float avg_tat = 0;
float avg_wt = 0;

void take_input() 
{
	printf("Enter the number of jobs: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
	{
		printf("Enter the arrival time of job %d: ", i+1);
		scanf("%d", &job[i].at);
		printf("Enter the burst time of job %d: ", i+1);
		scanf("%d", &job[i].bt);
		printf("Enter the name of job %d: ", i+1);
		scanf("%s", job[i].name);
		job[i].tbt = job[i].bt;
		printf("\n");
	}
}

void sort() 
{
	struct job temp;
	for (i = 0; i < n; i++) 
	{
		for (j = i + 1; j < n; j++) 
		{
			if (job[i].at > job[j].at) 
			{
				temp = job[i];
				job[i] = job[j];
				job[j] = temp;
			}
		}
	}
}

void process() 
{
	int time = job[0].at;
	for (j = 0; j < n; j++) 
	{
		job[j].st = time;
		printf("| %d %s ", job[j].st, job[j].name);
		time += job[j].tbt;
		job[j].ct = time;
		job[j].tat = job[j].ct - job[j].at;
		job[j].wt = job[j].tat - job[j].bt;
		printf("%d |", job[j].ct);
	}
	printf("\n");
}

void print_output() 
{
	printf("\n\n");
	printf("\n---------------------------------------");
	printf("\n PName   AT   BT   TAT   WT ");
	printf("\n---------------------------------------");
	for (i = 0; i < n; i++) 
	{
		printf("\n%s      %d    %d    %d    %d", job[i].name, job[i].at, job[i].bt, job[i].tat, job[i].wt);
		avg_tat += job[i].tat;
		avg_wt += job[i].wt;
	}
	printf("\n-----------------------------------------");
	printf("\nThe average Turn Around Time is: %.2f", avg_tat / n);
	printf("\nThe average Waiting Time is: %.2f", avg_wt / n);
	printf("\n-----------------------------------------\n");
}

int main() 
{
	take_input();
	sort();
	process();
	print_output();
	return 0;
}
