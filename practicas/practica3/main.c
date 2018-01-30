#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberOfSegments;
    int totalTime;

    int *distances;
    int *speeds;

    scanf("%d %d", &numberOfSegments, &totalTime);
    distances = (int *)malloc(sizeof(int) * numberOfSegments);
    speeds = (int *)malloc(sizeof(int) * numberOfSegments);

    for (int i = 0; i < numberOfSegments; ++i)
    {
        scanf("%d %d", distances + i, speeds + i);
    }

    // print inputs
    // printf("", );

    return 0;
}
