#include <stdio.h>

void sort_by_priority(int n, int at[], int bt[], int priority[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
            }
        }
    }
}

int main() {
    int bt[20], at[20], ct[20], tat[20], wt[20], priority[20];
    int n;
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time, burst time, and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival time of process[%d]: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Priority of process[%d]: ", i + 1);
        scanf("%d", &priority[i]);
    }

    sort_by_priority(n, at, bt, priority);

    ct[0] = bt[0] + at[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nTABLE:\n");
    printf("PId\t AT\t BT\t Priority\t CT\t TAT\t WT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t %d\t %d\t %d\t\t %d\t %d\t %d\n", i + 1, at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
    printf("Average Waiting Time = %.2f\n", totalWT / n);

    return 0;
}
