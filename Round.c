#include <stdio.h>

int main() {
    int n, quantum;
    int burst[100], remaining[100];
    int waiting[100] = {0};
    int turnaround[100] = {0};
    double totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    int time = 0;
    int done = 0;

    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                int executionTime = (remaining[i] < quantum) ? remaining[i] : quantum;
                remaining[i] -= executionTime;
                time += executionTime;
                turnaround[i] = time;
                if (remaining[i] == 0) {
                    done++;
                    waiting[i] = turnaround[i] - burst[i];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waiting[i];
        totalTurnaroundTime += turnaround[i];
    }

    double averageWaitingTime = totalWaitingTime / n;
    double averageTurnaroundTime = totalTurnaroundTime / n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, burst[i], waiting[i], turnaround[i]);
    }

    printf("Average Waiting Time: %.2lf\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", averageTurnaroundTime);

    return 0;
}
