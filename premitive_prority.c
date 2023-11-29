#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int priority;
    int burst_time;
    int remaining_time;
    int arrival_time;
};

int findHighestPriorityProcess(struct Process processes[], int n, int current_time) {
    int highest_priority = -1;
    int highest_priority_index = -1;

    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
            if (highest_priority == -1 || processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                highest_priority_index = i;
            }
        }
    }

    return highest_priority_index;
}

void priorityPreemptiveScheduling(struct Process processes[], int n) {
    int current_time = 0;
    int completed = 0;
    int turnaround_time[n], waiting_time[n];
    float total_turnaround_time = 0, total_waiting_time = 0;

    printf("Process\tPriority\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n) {
        int index = findHighestPriorityProcess(processes, n, current_time);

        if (index == -1) {
            current_time++;
            continue;
        }

        processes[index].remaining_time--;
        current_time++;

        if (processes[index].remaining_time == 0) {
            completed++;
            int completion_time = current_time;
            int turnaround = completion_time - processes[index].arrival_time;
            int waiting = turnaround - processes[index].burst_time;

            total_turnaround_time += turnaround;
            total_waiting_time += waiting;

            printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                   processes[index].id, processes[index].priority, processes[index].burst_time,
                   processes[index].arrival_time, completion_time, turnaround, waiting);
        }
    }

    float average_turnaround_time = total_turnaround_time / n;
    float average_waiting_time = total_waiting_time / n;

    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
    printf("Average Waiting Time: %.2f\n", average_waiting_time);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter the priority, burst time, and arrival time for process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].priority, &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    priorityPreemptiveScheduling(processes, n);

    return 0;
}
