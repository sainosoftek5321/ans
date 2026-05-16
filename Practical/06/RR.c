// 3. Round Robin Scheduling

#include<stdio.h>

int main()
{
    int n, i, time = 0, remain, flag = 0, ts;
    int at[10], bt[10], rt[10];
    float wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);

        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &ts);

    for(time = 0, i = 0; remain != 0;)
    {
        if(rt[i] <= ts && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if(rt[i] > 0)
        {
            rt[i] -= ts;
            time += ts;
        }

        if(rt[i] == 0 && flag == 1)
        {
            remain--;

            wt += time - at[i] - bt[i];
            tat += time - at[i];

            flag = 0;
        }

        if(i == n - 1)
            i = 0;
        else if(at[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\nAverage Waiting Time = %f", wt / n);
    printf("\nAverage Turnaround Time = %f", tat / n);

    return 0;
}