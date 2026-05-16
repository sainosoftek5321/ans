// C Program for SJF (Shortest Job First) Scheduling

#include <stdio.h>

int main()
{
    // Matrix for storing:
    // Process ID, Burst Time, Waiting Time, Turnaround Time
    int A[100][4];

    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;

    printf("Enter number of process: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");

    // User input for Burst Time and assigning Process ID
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);

        A[i][0] = i + 1;
    }

    // Sorting processes according to Burst Time
    for(i = 0; i < n; i++)
    {
        index = i;

        for(j = i + 1; j < n; j++)
        {
            if(A[j][1] < A[index][1])
                index = j;
        }

        // Swap Burst Time
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;

        // Swap Process ID
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }

    // Waiting Time for first process is 0
    A[0][2] = 0;

    // Calculate Waiting Time
    for(i = 1; i < n; i++)
    {
        A[i][2] = 0;

        for(j = 0; j < i; j++)
            A[i][2] += A[j][1];

        total += A[i][2];
    }

    avg_wt = (float)total / n;
    total = 0;

    printf("\nP\tBT\tWT\tTAT\n");

    // Calculate Turnaround Time and display data
    for(i = 0; i < n; i++)
    {
        A[i][3] = A[i][1] + A[i][2];

        total += A[i][3];

        printf("P%d\t%d\t%d\t%d\n",
               A[i][0],
               A[i][1],
               A[i][2],
               A[i][3]);
    }

    avg_tat = (float)total / n;

    printf("\nAverage Waiting Time = %f", avg_wt);
    printf("\nAverage Turnaround Time = %f", avg_tat);

    return 0;
}