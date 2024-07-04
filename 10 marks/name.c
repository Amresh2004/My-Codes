#include <stdio.h>
#include <string.h>

struct stud
{
    int rno;
    char name[20];
    int age;
} s[10];

// Function declarations
void Quicksort(struct stud a[], int lb, int ub);
int partition(struct stud a[], int lb, int ub);

int main()
{
    int i = 0, n;
    FILE *fp1, *fp;
    fp = fopen("emp.txt", "r");
    fp1 = fopen("sortonname.txt", "w");

    while (!feof(fp))
    {
        fscanf(fp, "%d%s%d", &s[i].rno, s[i].name, &s[i].age);
        i++;
    }

    n = i - 1;
    Quicksort(s, 0, n - 1);

    for (i = 0; i < n; i++)
    {
        fprintf(fp1, "%d\t%s\t%d\n", s[i].rno, s[i].name, s[i].age);
    }

    fclose(fp);
    fclose(fp1);

    return 0;
}

void Quicksort(struct stud a[], int lb, int ub)
{
    int p;
    if (lb < ub)
    {
        p = partition(a, lb, ub);
        Quicksort(a, lb, p - 1);
        Quicksort(a, p + 1, ub);
    }
}

int partition(struct stud a[], int lb, int ub)
{
    char pivot[20];
    strcpy(pivot, a[lb].name);
    int s = lb + 1;
    struct stud temp;
    while (s <= ub)
    {
        while (strcmp(a[s].name, pivot) < 0)
        {
            s++;
        }
        while (strcmp(a[ub].name, pivot) > 0)
        {
            ub--;
        }
        if (s < ub)
        {
            temp = a[s];
            a[s] = a[ub];
            a[ub] = temp;
        }
    }
    if (s > ub)
    {
        temp = a[lb];
        a[lb] = a[ub];
        a[ub] = temp;
    }
    return (ub);
}
