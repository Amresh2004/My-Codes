#include<stdio.h>
int L_S(int a[],int n,int key)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        return i;
    }
    return -1;
}
int main()
{
    int i,n,x,key;
    printf("Enter the size o array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the data:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter the elements to search:");
    scanf("%d",&key);
    x=L_S(a,n,key);
    if(x==0)
    {
        printf("Elements not found\n");
    }
    else
    {
        printf("Element found at %d",x);
    }
}