#include<stdio.h>
void main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int pn[n], bt[n], wt[n], tat[n], ct[n], i, at[n];
    for(i=0;i<n;i++){
    pn[i]=i+1;
    printf("Enter the burst time for process %d: ", pn[i]);
    scanf("%d",&bt[i]);
    printf("Enter the arrival time for process %d: ", pn[i]);
    scanf("%d",&at[i]);
    }
    int temp=0;
    for(i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                temp=pn[j];
                pn[j]=pn[j+1];
                pn[j+1]=temp;
            }
        }
        int tat_sum=0,wt_sum=0;
        for(i=0;i<n;i++){
            if(at[i]>ct[i-1])
            ct[i]=at[i]+bt[i];
            else
            ct[i]=ct[i-1]+bt[i];
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
            tat_sum+=tat[i];
            wt_sum+=wt[i];
        }
        float tat_avg=tat_sum/n, wt_avg= wt_sum/n;
        printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
        for(i=0;i<n;i++){
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",pn[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        }
        printf("TAT Average:%f\n",tat_avg);
        printf("WT Average:%f\n",wt_avg);
    }
}
