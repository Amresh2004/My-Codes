#include <stdio.h>
int main() 
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], P[n], CT[n], TAT[n], WT[n];
    float total_TAT = 0, total_WT = 0;

    for (int i = 0; i < n; i++) 
    {
        printf("Enter AT, BT, and P for P%d: ", i + 1);
        scanf("%d %d %d", &AT[i], &BT[i], &P[i]);
    }
    
    for (int i = 0; i < n; i++) 
    {
        if (i == 0) 
        {
            CT[i] = AT[i] + BT[i];
        } 
        else 
        {
            if (CT[i - 1] > AT[i]) 
            {
                CT[i] = CT[i - 1] + BT[i];
            } 
            else 
            {
                CT[i] = AT[i] +BT[i];
            }
        }
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        total_TAT += TAT[i];
        total_WT += WT[i];
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", i + 1, AT[i], BT[i], P[i], CT[i], TAT[i], WT[i]);
    }
    printf("\nAvg TAT: %.2f\nAvg WT: %.2f\n", total_TAT / n, total_WT / n);

    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) printf(" P%d |", i + 1);
    printf("\n0");
    for (int i = 0; i < n; i++) printf("   %d", CT[i]);
    printf("\n");
    return 0;
}
