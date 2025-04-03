#include <stdio.h>
#include <stdbool.h>

void shortestJobFirst() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pn[n], bt[n], wt[n], tat[n], ct[n], at[n];
    int completed[n]; // Array to track if a process is completed

    // Input process details
    for (int i = 0; i < n; i++) {
        pn[i] = i + 1;
        printf("Enter the burst time for process %d: ", pn[i]);
        scanf("%d", &bt[i]);
        printf("Enter the arrival time for process %d: ", pn[i]);
        scanf("%d", &at[i]);
        completed[i] = 0; // Initialize as not completed
    }

    int currentTime = 0;
    int completedProcesses = 0;
    float totalTAT = 0, totalWT = 0;

    while (completedProcesses < n) {
        int shortestJob = -1;
        int minBurstTime = 9999; // Initialize with a large value

        // Find the shortest job that has arrived and is not completed
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && completed[i] == 0) {
                if (bt[i] < minBurstTime) {
                    minBurstTime = bt[i];
                    shortestJob = i;
                }
            }
        }

        // If no process is available, increment time
        if (shortestJob == -1) {
            currentTime++;
        } else {
            // Execute the shortest job
            ct[shortestJob] = currentTime + bt[shortestJob];
            tat[shortestJob] = ct[shortestJob] - at[shortestJob];
            wt[shortestJob] = tat[shortestJob] - bt[shortestJob];

            totalTAT += tat[shortestJob];
            totalWT += wt[shortestJob];

            completed[shortestJob] = 1;
            completedProcesses++;
            currentTime = ct[shortestJob];
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
    shortestJobFirst();
    return 0;
}
