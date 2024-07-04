#include<stdio.h>
int S_S(int a[],int n,int key)
{
    int i=0;
    a[n]=key;
    while(a[i]!=key)
    {
        i++;
    }
    return i;
}
int main()
{
    int i,n,key,position;
    printf("enter thr size of array:\n");
    scanf("%d",&n);
    int a[n];
    printf("enter thr data:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n Enter thr elements to serach:");
    scanf("%d",&key);
    if(position==-1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at position %d",position);
    }
}