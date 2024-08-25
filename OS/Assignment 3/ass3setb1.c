/*include<stdio.h>
 #include<string.h>
 struct job
 {
 char name[20];
 int at,bt,ct,tat,wt,st,tbt;
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
 printf("Enter the arrival time of the job: ");
 scanf("%d",&job[i].at);
 printf("Enter the burst time of the job: ");
 scanf("%d",&job[i].bt);
 printf("Enter the name of the job: ");
 scanf("%s",job[i].name);
 job[i].tbt=job[i].bt;
 printf("\n\n");
 }
 }
 // to calculate the tat n wt
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
 printf("%d| %s \t",time,job[jno].name);
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
 int i,min=999,k;
 for(i=0;i<n;i++)
 if(job[i].at<=time && job[i].tbt!=0)
 {
 if(min>job[i].tbt)
 {
 min=job[i].tbt;
 k=i;
 }
 }
 return k;
 }
 //to print the output table
 void print_output()
 {
 printf("\n\n");
 printf("\n----------------------------------------------");
 printf("\n pname at bt tat wt ");
 printf("\n----------------------------------------------");
 for(i=0;i<n;i++)
 {
 printf("\n%s \t %d \t %d %d %d 
",job[i].name,job[i].at,job[i].bt,job[i].tat,job[i].wt);
 avg_tat=avg_tat+(float)(job[i].tat);
 avg_wt=avg_wt+(float)(job[i].wt);
 }
 printf("\n----------------------------------------------");
 printf("\navg waiting time is %f",avg_wt/n);
 printf("\navg turn around time is %f",avg_tat/n);
 
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
 process();
 print_output();
 }*/



/*include<stdio.h>
#include<string.h>
#include<stdlib.h>  // Include this for rand() function

struct job {
    char name[20];
    int at, bt, ct, tat, wt, st, tbt;
} job[10];

int jno, n, i, j;
float avg_tat = 0;
float avg_wt = 0;

// Function to take input for job details
void take_input() {
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time of job %d: ", i + 1);
        scanf("%d", &job[i].at);
        printf("Enter the burst time of job %d: ", i + 1);
        scanf("%d", &job[i].bt);
        printf("Enter the name of job %d: ", i + 1);
        scanf("%s", job[i].name);
        job[i].tbt = job[i].bt;
        printf("\n");
    }
}

// Function to process jobs and calculate CT, TAT, and WT
void process() {
    int time = 0, cnt = 0, i;
    char prev_job[20] = "", cur_job[20];

    while (1) {
        jno = getjob(time);
        job[jno].tbt--;
        strcpy(cur_job, job[jno].name);

        if (strcmp(cur_job, prev_job) != 0) {
            printf("%d | %s \t", time, job[jno].name);
        }

        time++;

        if (job[jno].tbt == 0) {
            job[jno].ct = time;
            job[jno].tat = time - job[jno].at;
            job[jno].wt = job[jno].tat - job[jno].bt;
            cnt++;
        }

        strcpy(prev_job, cur_job);

        if (cnt == n)
            break;
    }

    printf("End Time: %d\n", time);
}

// Function to get the job with the minimum burst time at the current time
int getjob(int time) {
    int i, min = 999, k = -1;

    for (i = 0; i < n; i++) {
        if (job[i].at <= time && job[i].tbt > 0) {
            if (job[i].tbt < min) {
                min = job[i].tbt;
                k = i;
            }
        }
    }

    return k;
}

// Function to print the output table
void print_output() {
    printf("\n----------------------------------------------");
    printf("\nPName\tAT\tBT\tTAT\tWT");
    printf("\n----------------------------------------------");

    for (i = 0; i < n; i++) {
        printf("\n%s\t%d\t%d\t%d\t%d", job[i].name, job[i].at, job[i].bt, job[i].tat, job[i].wt);
        avg_tat += (float)job[i].tat;
        avg_wt += (float)job[i].wt;
    }

    printf("\n----------------------------------------------");
    printf("\nAverage Waiting Time: %f", avg_wt / n);
    printf("\nAverage Turn Around Time: %f\n", avg_tat / n);
}

int main() {
    take_input();
    process();
    print_output();

    // Second round of job processing with new random burst times and arrival times
    for (i = 0; i < n; i++) {
        job[i].bt = rand() % 10 + 1;
        job[i].tbt = job[i].bt;
        job[i].at = job[i].ct + 2;
    }

    process();
    print_output();

    return 0;
}
*/



#include <stdio.h>
#include <string.h>

struct job {
    char name[20];
    int at, bt, ct, tat, wt, st, tbt;
} job[10];

int n, i, j;
float avg_tat = 0;
float avg_wt = 0;

void take_input() {
    printf("Enter the no of jobs : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time of the job: ");
        scanf("%d", &job[i].at);
        printf("Enter the burst time of the job: ");
        scanf("%d", &job[i].bt);
        printf("Enter the name of the job: ");
        scanf("%s", job[i].name);
        job[i].tbt = job[i].bt;
        printf("\n\n");
    }
}

// Function to get the index of the job to be executed next
int getjob(int time) {
    int i, min = 9999, k = -1;
    for (i = 0; i < n; i++) {
        if (job[i].at <= time && job[i].tbt > 0) {
            if (job[i].tbt < min) {
                min = job[i].tbt;
                k = i;
            }
        }
    }
    return k;
}

// Function to process the jobs and calculate times
void process() {
    int time = 0, cnt = 0;
    char prev_job[20] = "";
    char cur_job[20];

    while (cnt < n) {
        int jno = getjob(time);
        if (jno == -1) {
            time++;
            continue;
        }
        job[jno].tbt--;
        strcpy(cur_job, job[jno].name);

        if (strcmp(cur_job, prev_job) != 0) {
            printf("%d| %s\t", time, job[jno].name);
        }

        time++;

        if (job[jno].tbt == 0) {
            job[jno].ct = time;
            job[jno].tat = job[jno].ct - job[jno].at;
            job[jno].wt = job[jno].tat - job[jno].bt;
            cnt++;
        }

        strcpy(prev_job, cur_job);
    }
    printf("End Time %d\n", time);
}

// Function to print the output table
void print_output() {
    printf("\n\n");
    printf("----------------------------------------------\n");
    printf(" PName\tAT\tBT\tTAT\tWT\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", job[i].name, job[i].at, job[i].bt, job[i].tat, job[i].wt);
        avg_tat += job[i].tat;
        avg_wt += job[i].wt;
    }
    printf("----------------------------------------------\n");
    printf("Avg Waiting Time: %f\n", avg_wt / n);
    printf("Avg Turn Around Time: %f\n", avg_tat / n);
}

int main() {
    take_input();
    process();
    print_output();

    return 0;
}

