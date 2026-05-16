#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[100], n, head, disk_size, direction;
    int i, j, temp, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter direction (0 = Left, 1 = Right): ");
    scanf("%d", &direction);

    // Sort requests
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(req[j] > req[j + 1])
            {
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    int index;

    for(i = 0; i < n; i++)
    {
        if(head < req[i])
        {
            index = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d ", head);

    // Move Right
    if(direction == 1)
    {
        for(i = index; i < n; i++)
        {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }

        total += abs((disk_size - 1) - head);
        head = disk_size - 1;

        for(i = index - 1; i >= 0; i--)
        {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }
    }

    // Move Left
    else
    {
        for(i = index - 1; i >= 0; i--)
        {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }

        total += abs(0 - head);
        head = 0;

        for(i = index; i < n; i++)
        {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d ", head);
        }
    }

    printf("\n\nTotal Seek Time = %d\n", total);

    return 0;
}