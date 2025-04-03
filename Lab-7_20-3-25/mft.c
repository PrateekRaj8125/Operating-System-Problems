#include <stdio.h>

void multiprogrammingMFT() {
    int totalMemory, n;

    // Input total memory size
    printf("Enter the total memory available (in KB): ");
    scanf("%d", &totalMemory);

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processSize[n], allocated[n];
    int remainingMemory = totalMemory;

    // Input process sizes
    for (int i = 0; i < n; i++) {
        printf("Enter the memory required for process %d (in KB): ", i + 1);
        scanf("%d", &processSize[i]);
        allocated[i] = 0; // Initially, no process is allocated memory
    }

    // Memory allocation using First Fit
    for (int i = 0; i < n; i++) {
        if (processSize[i] <= remainingMemory) {
            allocated[i] = 1; // Allocate memory to the process
            remainingMemory -= processSize[i];
        }
    }

    // Output the results
    printf("\nProcess\tMemory Required\tAllocated\tRemaining Memory\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%s\t\t%d\n", i + 1, processSize[i],
               allocated[i] ? "Yes" : "No", allocated[i] ? remainingMemory : remainingMemory);
    }

    printf("\nTotal Memory: %d KB\n", totalMemory);
    printf("Remaining Memory: %d KB\n", remainingMemory);
}

int main() {
    multiprogrammingMFT();
    return 0;
}