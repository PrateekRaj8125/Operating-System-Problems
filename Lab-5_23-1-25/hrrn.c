#include <stdio.h>

void highestResponseRatioNext() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pn[n], at[n], bt[n], ct[n], tat[n], wt[n], completed[n];
    float responseRatio[n];
    int currentTime = 0, completedProcesses = 0;
    float totalTAT = 0, totalWT = 0;

    // Input process details
    for (int i = 0; i < n; i++) {
        pn[i] = i + 1;
        printf("Enter the arrival time for process %d: ", pn[i]);
        scanf("%d", &at[i]);
        printf("Enter the burst time for process %d: ", pn[i]);
        scanf("%d", &bt[i]);
        completed[i] = 0; // Mark process as not completed
    }

    // HRRN Scheduling
    while (completedProcesses < n) {
        int selectedProcess = -1;
        float maxResponseRatio = -1.0;

        // Calculate response ratio for each process and select the highest
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && completed[i] == 0) {
                int waitingTime = currentTime - at[i];
                responseRatio[i] = (float)(waitingTime + bt[i]) / bt[i];
                if (responseRatio[i] > maxResponseRatio) {
                    maxResponseRatio = responseRatio[i];
                    selectedProcess = i;
                }
            }
        }

        if (selectedProcess == -1) {
            // No process is ready, increment time
            currentTime++;
        } else {
            // Execute the selected process
            currentTime += bt[selectedProcess];
            ct[selectedProcess] = currentTime; // Completion time
            tat[selectedProcess] = ct[selectedProcess] - at[selectedProcess]; // Turnaround time
            wt[selectedProcess] = tat[selectedProcess] - bt[selectedProcess]; // Waiting time

            totalTAT += tat[selectedProcess];
            totalWT += wt[selectedProcess];
            completed[selectedProcess] = 1; // Mark process as completed
            completedProcesses++;
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
    highestResponseRatioNext();
    return 0;
}