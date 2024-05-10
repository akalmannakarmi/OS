// Implement FCFS disk scheduling algorithm

#include <stdio.h>
#include <math.h>

int main(){
    int n,seek_count=0,cur_track,distance,head=50;
    printf("Enter the size of n:");
    scanf("%d",&n);
    int arr[n]; 
    printf("Enter the value of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        cur_track=arr[i];
        // calculate absolute distance
        distance = fabs(head-cur_track);

        // increase the total count
        seek_count += distance;

        // accessed track is now new head
        head = cur_track;
    }

    printf("Total number of seek operations: %d\n",seek_count);

    printf("Seek Sequence is\n");

    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}