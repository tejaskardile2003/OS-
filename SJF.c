#include <stdio.h>

int main() {
    int n, burst[100], waiting[100], turnaround[100];
    double totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    waiting[0] = 0;

    for (int i = 1; i < n; i++) {
        waiting[i] = 0;
        for (int j = 0; j < i; j++) {
            waiting[i] += burst[j];
        }
    }

    for (int i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];
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
