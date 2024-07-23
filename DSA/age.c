#include<stdio.h>
struct stud
{
    int rno;
    char name[20];
    int age;
}s[10];
main()
{
    int i=0,n,j;
    FILE *fp1,*fp;
    fp=fopen("emp.txt","r");
    fp1=fopen("sortonage.txt","w");
    while(!feof(fp))
    {
        fscanf(fp,"%d%s%d",&s[i].rno,s[i].name,&s[i].age);
        i++;
    }
    n=i-1;
    Quicksort(s,0,n-1);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d\t%s\t%d\t",s[i].rno,s[i].name,s[i].age);
    }
}
void Quicksort(struct stud a[10],int ub,int lb)
{
    int p;
    if(lb<ub)
    {
        p=partition(a,lb,ub);
        Quicksort(a,lb,p-1);
        Quicksort(a,p+1,ub);
    }
}
int partition(struct stud a[],int lb,int ub)
{
    int pivot=a[lb].age;
    int s=lb+1;
    struct stud temp;
    while(s<ub)
    {
        while(a[s].age <= pivot)
        {
            s++;
        }
        while(a[ub].age > pivot)
        {
            ub--;
        }
        if(s<ub)
        {
            temp=a[s];
            a[s]=a[ub];
            a[ub]=temp;
        }
    }
    if(s>ub)
    {
        temp=a[lb];
        a[lb]=a[ub];
        a[ub]=temp;
    }
    return(ub);
}