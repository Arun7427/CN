#include <stdio.h>

int main()
{
    int windowSize, totalFrames, i;
    int frames[50];

    printf("Enter window size: ");
    scanf("%d", &windowSize);

    printf("\nEnter number of frames to transmit: ");
    scanf("%d", &totalFrames);

    printf("\nEnter %d frames: ", totalFrames);

    for (i = 0; i < totalFrames; i++)
    {
        scanf("%d", &frames[i]);
    }

    printf("\nSliding Window Protocol Simulation\n");
    printf("Sender sends %d frames at a time and waits for acknowledgement.\n\n",
           windowSize);

    for (i = 0; i < totalFrames; i++)
    {
        printf("%d ", frames[i]);

        if ((i + 1) % windowSize == 0)
        {
            printf("\nAcknowledgement of above frames is received by sender\n\n");
        }
    }

    if (totalFrames % windowSize != 0)
    {
        printf("\nAcknowledgement of above frames is received by sender\n");
    }

    return 0;
}
