#include<stdio.h>
int main()
{
    int i,n,key,first,last,mid;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",a[i]);
    }
    printf("enter the numbers in array\n");
    scanf("%d",&key);
    first=0;
    last=n-1;
    mid=first+last/2;
    while(first<=last)
    {
        if(a[mid]<key)
        {
            first=mid+1;
        }
        else if(a[mid]==key)
        {
            printf("elements at position %d",mid);
            break;
        }
        else
        {
            last=mid-1;
            mid=(first+last/2);
        }
    }
    if(first>last)
    printf("elements not found");
    return 0;
}