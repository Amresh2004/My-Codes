#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct city
{
    char name[20];
    int code;
} city[100];

int read_file(struct city *a)
{
    int i = 0;
    FILE *fp;

    if ((fp = open("city.txt", "r")) != NULL)
    {
        while (scanf(fp, "%s%d", a[i].name, &a[i].code) != EOF)
        {
            i++;
        }
        close(fp);
    }

    return i;
}

void I_search(struct city *a, int n, char x[20])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(a[i].name, x) == 0)
        {
            printf("\n%s=%d\n", a[i].name, a[i].code);
            break;
        }
    }
    if (i == n)
        printf("\nCity not found\n");
}

int main()
{
    char x[20];
    int n;
    n = read_file(city);
    printf("\nEnter the city\n");
    fgets(x, sizeof(x), stdin);
    // Remove the newline character from the input
    x[strcspn(x, "\n")] = '\0';
    I_search(city, n, x);

    return 0;
}
