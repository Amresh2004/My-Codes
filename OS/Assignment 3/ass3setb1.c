


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

