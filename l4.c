// Simulate Round Robin schedualing algorithm

#include<stdio.h>
void main()
{
    int i, NOP,sum=0,count=0,y,quant,wt=0,tat=0,at[10],bt[10],temp[10];
    float avg_wt,avg_tat;
    printf("Enter total number of process in the system:");
    scanf("%d",&NOP);
    y=NOP;
    for(i=0;i<NOP;i++)
    {
        printf("\n Enter the Arrival and Burst time of the process[%d]:\n",i+1);
        printf("\n Enter the Arrival time:\t");
        scanf("%d",&at[i]);
        printf("\n Enter the Burst time:\t");
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
    }
    printf("\n Enter the Time Quantum for the process: \t");
    scanf("%d",&quant);
    printf("\n Process no.\t Burst Time \t Turn Around Time \t Waiting Time");
    for(sum=0,i=0;y!=0;)
    {
        if(temp[i]<=quant && temp[i]>0)
        {
            sum=sum+temp[i];
            temp[i]=0;
            count=1;
        }
        else if(temp[i]>0)
        {
            temp[i]=temp[i]-quant;
            sum=sum+quant;
        }
        if(temp[i]==0 && count==1)
        {
            y--;
            printf("\n Process no.[%d]\t\t %d\t\t %d\t\t\t %d",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]);
            wt=wt+sum-at[i]-bt[i];
            tat=tat+sum-at[i];
            count=0;
        }
        if(i==NOP-1)
        {
            i=0;
        }
        else if(at[i+1]<=sum)
        {
            i++;
        }
        else
        {
            i=0;
        }

    }
    avg_wt=wt*1.0/NOP;
    avg_tat=tat*1.0/NOP;
    printf("\n Average Waiting Time:\t%f",avg_wt);
    printf("\n Average Turn Around Time Time:\t%f",avg_tat);

}