#include <stdio.h>

int main()
{
    int pages[50], frame[10];
    int n, f, i, j, k, pos = 0, faults = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            frame[pos] = pages[i];
            pos = (pos + 1) % f;
            faults++;

            printf("\nPage %d -> ", pages[i]);

            for(k = 0; k < f; k++)
            {
                printf("%d ", frame[k]);
            }
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}