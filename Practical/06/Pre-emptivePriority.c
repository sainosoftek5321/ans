// 2. Pre-emptive Priority Scheduling

#include<stdio.h>

int main()
{
    int n, i, time = 0, highest;
    int at[10], bt[10], rt[10], pr[10];
    int wt = 0, tat = 0, finish, count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time, Burst Time and Priority of P%d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);

        rt[i] = bt[i];
    }

    pr[9] = 9999;

    while(count != n)
    {
        highest = 9;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && pr[i] < pr[highest] && rt[i] > 0)
                highest = i;
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0)
        {
            count++;
            finish = time;

            wt += finish - bt[highest] - at[highest];
            tat += finish - at[highest];
        }
    }

    printf("\nAverage Waiting Time = %f", (float)wt / n);
    printf("\nAverage Turnaround Time = %f", (float)tat / n);

    return 0;
}