// 1. Pre-emptive SJF (Shortest Remaining Time First)

#include<stdio.h>

int main()
{
    int n, i, time = 0, smallest, count = 0;
    int bt[10], rt[10], at[10];
    int wt = 0, tat = 0, finish_time;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    rt[9] = 9999;

    while(count != n)
    {
        smallest = 9;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
                smallest = i;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest] == 0)
        {
            count++;
            finish_time = time;

            wt += finish_time - bt[smallest] - at[smallest];
            tat += finish_time - at[smallest];
        }
    }

    printf("\nAverage Waiting Time = %f", (float)wt / n);
    printf("\nAverage Turnaround Time = %f", (float)tat / n);

    return 0;
}