#include<stdio.h>
struct city
{
    char name[20];
    int std;
}s[10];
int main()
{
    int i=0,n,j,flag=0;
    FILE *fp1;
    char c[20];
    fp1=fopen("cities.txt","r");
    while(!feof(fp1))
    {
        fscanf(fp1,"%d %s",&s[i].name,s[i].std);
        i++;
    }
    n=i-1;
    printf("entera city name:");
    gets(c);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].name,c)==0)
        {
            printf("STD codes:- %d",s[i].std);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("city not found");
    }
    else
    {
        printf("city found");
    }
}
