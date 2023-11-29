#include <stdio.h>

int main() {
    int bt[20], at[20], ct[20], tat[20], wt[20], completed[20] = {0};
    int n, min, minIndex = 0;
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival time of process[%d]: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int currentTime = 0, processesCompleted = 0;
    while (processesCompleted < n) {
        min = 9999; // Initializing min with a very large value

        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (completed[i] == 0 && at[i] <= currentTime && bt[i] < min) {
                min = bt[i];
                minIndex = i;
            }
        }

        // No process found, increment current time
        if (min == 9999) {
            currentTime++;
            continue;
        }

        // Execute the selected process
        ct[minIndex] = currentTime + bt[minIndex];
        tat[minIndex] = ct[minIndex] - at[minIndex];
        wt[minIndex] = tat[minIndex] - bt[minIndex];
        completed[minIndex] = 1;
        currentTime = ct[minIndex];
        processesCompleted++;
    }

    printf("\nTABLE:\n");
    printf("PId\t AT\t BT\t CT\t TAT\t WT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
    printf("Average Waiting Time = %.2f\n", totalWT / n);

    return 0;
}



/*Initialization:

int currentTime = 0, processesCompleted = 0;: Initialize variables to keep track of the current time and the number of processes that have completed their execution.
While Loop:

while (processesCompleted < n) {: The loop continues until all processes have completed their execution (processesCompleted reaches the total number of processes n).
Finding the shortest job among arrived processes:

min = 9999;: Initialize min to a very large value. This value is used as a placeholder for finding the process with the shortest burst time.
The loop iterates through the processes to find the process with the shortest burst time that has already arrived (at[i] <= currentTime) and has not been completed (completed[i] == 0).
if (completed[i] == 0 && at[i] <= currentTime && bt[i] < min) {: Checks if the process has arrived, hasn't been completed, and has a burst time shorter than the current minimum (min). If so, update min with the new minimum burst time (bt[i]) and store the index of this process in minIndex.
No process found:

if (min == 9999) {: If no eligible process is found to execute at the current time, increment the currentTime by 1 and continue to the next iteration of the loop. This step ensures the algorithm's progress in time if no processes are available for execution at the current time.
Execution of the selected process:

If a process is selected (with the shortest burst time among arrived processes), calculate its completion time (ct[minIndex]), turnaround time (tat[minIndex]), and waiting time (wt[minIndex]).
Mark the selected process as completed by setting completed[minIndex] to 1.
Update currentTime to the completion time of the executed process.
Increment processesCompleted to keep track of the number of processes that have finished execution.*/