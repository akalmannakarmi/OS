// Simulate SJF CPU schedualing algorithm

#include<stdio.h>
int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("\n Enter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p[%d]:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[i])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]+=bt[j];
            total+=wt[i];
        }
    }
    avg_wt=(float)total/n;
    total=0;
    printf("\n Process \tBurst Time \tWaiting Time \tTurn Around Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\n p[%d]\t\t %d\t\t %d\t\t %d",p[i],bt[i],wt[i],tat[i]);

    }
    avg_tat=(float)total/n;
    printf("\n Average Waiting Time=%f",avg_wt);
     printf("\n Average Turn Around Time=%f",avg_tat);
    return 0;
}