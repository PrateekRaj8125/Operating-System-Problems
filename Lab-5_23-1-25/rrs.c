#include <stdio.h>

void roundRobinScheduling() {
    int n, timeQuantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pn[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    int completed = 0, currentTime = 0;
    float totalTAT = 0, totalWT = 0;

    // Input process details
    for (int i = 0; i < n; i++) {
        pn[i] = i + 1;
        printf("Enter the arrival time for process %d: ", pn[i]);
        scanf("%d", &at[i]);
        printf("Enter the burst time for process %d: ", pn[i]);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Remaining time is initially the burst time
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    // Round Robin Scheduling
    while (completed < n) {
        int executed = 0;

        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && rt[i] > 0) {
                executed = 1;

                if (rt[i] <= timeQuantum) {
                    // Process completes within the time quantum
                    currentTime += rt[i];
                    rt[i] = 0;
                    ct[i] = currentTime; // Completion time
                    tat[i] = ct[i] - at[i]; // Turnaround time
                    wt[i] = tat[i] - bt[i]; // Waiting time

                    totalTAT += tat[i];
                    totalWT += wt[i];
                    completed++;
                } else {
                    // Process does not complete within the time quantum
                    currentTime += timeQuantum;
                    rt[i] -= timeQuantum;
                }
            }
        }

        if (!executed) {
            // If no process was executed, increment time
            currentTime++;
        }
    }

    // Output the results
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pn[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT: %.2f\n", totalTAT / n);
    printf("Average WT: %.2f\n", totalWT / n);
}

int main() {
    roundRobinScheduling();
    return 0;
}