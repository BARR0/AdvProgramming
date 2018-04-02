#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    
    int boost = 0;

    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        scanf("%d%d%d%d%d%d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
        int opponentX;
        int opponentY;
        scanf("%d%d", &opponentX, &opponentY);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        
        int opponentDist = sqrt((x - opponentX) * (x - opponentX) + (y - opponentY) * (y - opponentY));

        int thrust;
        if (nextCheckpointAngle > 90 || nextCheckpointAngle < -90)
            thrust = 0;
        else if (boost = 0 && nextCheckpointDist > 5000 && opponentDist < 900)
        {
            boost = 1;
            printf("%d %d BOOST\n", nextCheckpointX, nextCheckpointY);
            continue;
        }
        else
            thrust = 100;
        

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        printf("%d %d %d\n", nextCheckpointX, nextCheckpointY, thrust);
    }

    return 0;
}