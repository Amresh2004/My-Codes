#include <stdio.h>
#include <string.h>
struct city
{
    int std;
    char name[20];
} s[10];
int main()
{
    int i = 0, n, j, flag = 0;
    FILE *fp1;
    char c[20];
    fp1 = fopen("emp.txt", "r");
    while (!feof(fp1))
    {
        fscanf(fp1, "%d%s", &s[i].std, s[i].name);
        i++;
    }
    n = i - 1;
    printf("Enter a city: ");
    fgets(c, sizeof(c), stdin);
    c[strcspn(c, "\n")] = '\0';  // Remove the newline character added by fgets
    for (i = 0; i < n; i++)
    {
        if (strcmp(s[i].name, c) == 0)
        {
            printf("STD codes: %d\n", s[i].std);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("City not found\n");
    }
    else
    {
        printf("City found\n");
    }
    fclose(fp1);
    return 0;
}
