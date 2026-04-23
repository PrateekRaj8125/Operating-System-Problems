/*Write a C program to implement Shortest Remaining Time First (SRTF) (preemptive scheduling) and compute CT, TAT, WT, and averages.*/
#include <stdio.h>
void shortestRemainingTimeFirst() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pn[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    int completed = 0, currentTime = 0, shortest = -1, minRemainingTime = 10000; // Use a large value
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

    // SRTF Scheduling
    while (completed < n) {
        shortest = -1;
        minRemainingTime = 10000; // Reset to a large value

        // Find the process with the shortest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && rt[i] > 0 && rt[i] < minRemainingTime) {
                minRemainingTime = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            // No process is ready to execute, increment time
            currentTime++;
        } else {
            // Execute the process with the shortest remaining time
            rt[shortest]--;
            currentTime++;

            // If the process is completed
            if (rt[shortest] == 0) {
                completed++;
                ct[shortest] = currentTime; // Completion time
                tat[shortest] = ct[shortest] - at[shortest]; // Turnaround time
                wt[shortest] = tat[shortest] - bt[shortest]; // Waiting time

                totalTAT += tat[shortest];
                totalWT += wt[shortest];
            }
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
    shortestRemainingTimeFirst();
    return 0;
}