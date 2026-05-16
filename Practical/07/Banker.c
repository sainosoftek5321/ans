#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    // n = number of processes
    // m = number of resource types
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m], avail[m];
    int finish[n], safeSeq[n];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Request Matrix
    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    // Initialize finish array
    for(i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    int count = 0;

    // Deadlock Detection Algorithm
    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > avail[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                // If process can be executed
                if(possible)
                {
                    for(k = 0; k < m; k++)
                    {
                        avail[k] += alloc[i][k];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // No process could be executed
        if(found == 0)
        {
            break;
        }
    }

    // Check deadlock
    if(count == n)
    {
        printf("\nSystem is NOT in Deadlock.\n");
        printf("Safe Sequence: ");

        for(i = 0; i < n; i++)
        {
            printf("P%d ", safeSeq[i]);
        }

        printf("\n");
    }
    else
    {
        printf("\nSystem is in Deadlock.\n");
        printf("Deadlocked Processes: ");

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                printf("P%d ", i);
            }
        }

        printf("\n");
    }

    return 0;
}