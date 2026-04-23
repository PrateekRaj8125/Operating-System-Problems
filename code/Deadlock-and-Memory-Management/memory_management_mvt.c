/*Write a C program to implement Multiprogramming with Variable Tasks (MVT) memory allocation.
Provide options to:

Add process
Remove process
Display memory status*/

#include <stdio.h>

void multiprogrammingMVT() {
    int totalMemory, remainingMemory, choice, processID = 1;

    // Input total memory size
    printf("Enter the total memory available (in KB): ");
    scanf("%d", &totalMemory);

    remainingMemory = totalMemory;

    // Arrays to store process details
    int processIDs[100], processSizes[100], allocated[100];
    int processCount = 0;

    // Initialize all processes as not allocated
    for (int i = 0; i < 100; i++) {
        allocated[i] = 0;
    }

    do {
        printf("\n1. Add Process\n2. Remove Process\n3. Display Memory Status\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Add a new process
                int processSize;
                printf("Enter the memory required for process %d (in KB): ", processID);
                scanf("%d", &processSize);

                if (processSize <= remainingMemory) {
                    // Allocate memory to the process
                    processIDs[processCount] = processID;
                    processSizes[processCount] = processSize;
                    allocated[processCount] = 1;
                    remainingMemory -= processSize;
                    printf("Process %d allocated %d KB memory.\n", processID, processSize);
                    processID++;
                    processCount++;
                } else {
                    printf("Not enough memory available to allocate %d KB.\n", processSize);
                }
                break;
            }

            case 2: {
                // Remove an existing process
                int removeID, found = 0;
                printf("Enter the process ID to remove: ");
                scanf("%d", &removeID);

                for (int i = 0; i < processCount; i++) {
                    if (allocated[i] && processIDs[i] == removeID) {
                        remainingMemory += processSizes[i];
                        allocated[i] = 0; // Mark process as deallocated
                        printf("Process %d removed, %d KB memory freed.\n", removeID, processSizes[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Process ID %d not found or already removed.\n", removeID);
                }
                break;
            }

            case 3: {
                // Display memory status
                printf("\nTotal Memory: %d KB\n", totalMemory);
                printf("Remaining Memory: %d KB\n", remainingMemory);
                printf("Allocated Processes:\n");
                printf("PID\tMemory Allocated\n");
                for (int i = 0; i < processCount; i++) {
                    if (allocated[i]) {
                        printf("%d\t%d KB\n", processIDs[i], processSizes[i]);
                    }
                }
                break;
            }

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    multiprogrammingMVT();
    return 0;
}