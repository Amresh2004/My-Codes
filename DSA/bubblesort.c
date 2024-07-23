#include<stdio.h>
void bubble_sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int i,n;
    printf("enter thr size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("enter thr rlrmrnts of array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    printf("sorted array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}