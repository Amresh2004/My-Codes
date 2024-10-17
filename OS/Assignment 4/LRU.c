

#include<stdio.h>
#define frame 3
int mem[frame][2]={-1,0,-1,0,-1,0};
int pagefault=0;
int n=15;
int a[]={7,3,5,8,5,8,3,6,7,3,6,7,8,5,3};
void mfu(int p)
{
    int k,f=0;
    for(k=0;k<frame;k++)
    {
        if(mem[k][0]==p)
        { 
           mem[k][1]=mem[k][1]+1;
           return;
        }
    } 
    printf("\n\n Page fault");
    pagefault++;
    for(k=0;k<frame;k++)
       if(mem[k][0]==-1)
       {
          mem[k][0]=p;
          mem[k][1]=0;
          return;
       }
     for(k=0;k<frame;k++)
        if(mem[k][1]<mem[f][1])
            f=k;
            mem[f][0]=p;
            mem[f][1]=0;
}
main()
{
    int i=0,k;
    for(i=0;i<n;i++) 
    {
       mfu(a[i]);
       for(k=0;k<frame;k++)
           printf("%2d",mem[k][0]);
           printf("\n\n");
     }
    printf("\nTotal No of Pagefault : %d",pagefault);
}
