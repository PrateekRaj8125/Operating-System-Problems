#include<stdio.h>
int main(){
    int r,n;
    printf("Enter no. of Processes: ");
    scanf("%d",&n);
    printf("Enter total resources: ");
    scanf("%d",&r);
    int alloc[n],max[n],need[n],available[n], totalallocr=0;
    int check[n];
    for (int i=0;i<n;i++)
    {
        printf("Enter Maximum Resources for Process %d: ",(i+1));
        scanf("%d",&max[i]);
        printf("Enter Allocated Resources for Process %d: ",(i+1));
        scanf("%d",&alloc[i]);
        need[i]=max[i]-alloc[i];
        totalallocr+=alloc[i];
        check[i]=-1;
    }
    int diff=r-totalallocr;
    int d=diff;
    printf("Escape Sequence:");
    while(diff<r){
        for(int i=0;i<n;i++){
            if(check[i]!=i){
                if(need[i]<=diff){
                    diff=diff-need[i]+max[i];
                    check[i]=i;
                    printf("P%d,",(i+1));
                }
            }
        }
        if(diff==d){
            printf("\nDeadlock Condition\n");
            return 0;
        }
        d=diff;
    }
    printf("\nTotal Resources:%d\n",r);
    printf("Current Available Resources:%d\n",diff);
}
