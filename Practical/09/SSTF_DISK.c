#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[100], visited[100];
    int n, head, i, j, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for(i = 0; i < n; i++)
    {
        int min = 9999, index = -1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && abs(req[j] - head) < min)
            {
                min = abs(req[j] - head);
                index = j;
            }
        }

        visited[index] = 1;
        total += min;
        head = req[index];

        printf("-> %d ", head);
    }

    printf("\n\nTotal Seek Time = %d\n", total);

    return 0;
}