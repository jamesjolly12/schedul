#include <stdio.h>

int main() {
    int bt[20], at[20], ct[20], tat[20], wt[20];
    int n, remainingTime[20], completed = 0;
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival time of process[%d]: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        remainingTime[i] = bt[i];
    }

    int currentTime = 0, minIndex = -1, min = 9999;

    while (completed != n) {
        min = 9999;
        minIndex = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && remainingTime[i] < min && remainingTime[i] > 0) {
                min = remainingTime[i];
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            currentTime++;
            continue;
        }

        remainingTime[minIndex]--;
        currentTime++;

        if (remainingTime[minIndex] == 0) {
            completed++;
            ct[minIndex] = currentTime;
            tat[minIndex] = ct[minIndex] - at[minIndex];
            wt[minIndex] = tat[minIndex] - bt[minIndex];
        }
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
