// C program for implementation of FCFS Scheduling

#include<stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    // Waiting time for first process is 0
    wt[0] = 0;

    // Calculating waiting time
    for(int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n,
                        int bt[], int wt[], int tat[])
{
    // Calculating turnaround time
    for(int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    // Find waiting time
    findWaitingTime(processes, n, bt, wt);

    // Find turnaround time
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes with details
    printf("Processes   Burst Time   Waiting Time   Turn Around Time\n");

    // Calculate total waiting time and turnaround time
    for(int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];

        printf("   %d", (i + 1));
        printf("\t\t%d", bt[i]);
        printf("\t\t%d", wt[i]);
        printf("\t\t%d\n", tat[i]);
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    printf("\nAverage Waiting Time = %f", avg_wt);
    printf("\nAverage Turn Around Time = %f", avg_tat);
}

// Driver code
int main()
{
    // Process IDs
    int processes[] = {1, 2, 3};

    int n = sizeof(processes) / sizeof(processes[0]);

    // Burst time of all processes
    int burst_time[] = {10, 5, 8};

    findavgTime(processes, n, burst_time);

    return 0;
}