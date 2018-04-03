#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PRIME 1000000007

struct Pixel
{
    long long max;
    long long min;
};

bool paint(int R, int C, long long D, struct Pixel canvas[R][C], int x, int y, long long b)
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            long long distance = abs(i - x) + abs(j - y);
            long long pixmax = (b + D * distance > 0) ? b + D * distance : 0;
            long long pixmin = (b - D * distance > 0) ? b - D * distance : 0;
            canvas[i][j].max = (pixmax < canvas[i][j].max || canvas[i][j].max == -1) ? pixmax : canvas[i][j].max;
            canvas[i][j].min = (pixmin > canvas[i][j].min || canvas[i][j].min == -1) ? pixmin : canvas[i][j].min;

            if (canvas[i][j].min > canvas[i][j].max)
            {
                return false;
            }
        }
    }
    return true;
}

int canvas_sum(int R, int C, struct Pixel canvas[R][C])
{
    int sum = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (canvas[i][j].min > canvas[i][j].max)
                return -1;
            sum = (sum + canvas[i][j].max) % PRIME;
        }
    }
    return sum;
}

void print_canvas(int R, int C, struct Pixel canvas[R][C])
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            printf("%lld\t", canvas[i][j].max);
        }
        printf("\n");
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        int R, C, N, D;
        scanf("%d%d%d%d", &R, &C, &N, &D);

        printf("Case #%d: ", i + 1);

        struct Pixel canvas[R][C];
        for (int j = 0; j < R; ++j)
        {
            for (int k = 0; k < C; ++k)
            {
                canvas[j][k].max = -1;
                canvas[j][k].min = -1;
            }
        }
        
        for (int j = 0; j < N; ++j)
        {
            int Ri, Ci, Bi;
            scanf("%d%d%d", &Ri, &Ci, &Bi);
            --Ri;
            --Ci;
            if (!paint(R, C, D, canvas, Ri, Ci, Bi))
            {
                for(int k = 0; k < N - j - 1; ++k)
                    scanf("%d%d%d", &Ri, &Ci, &Bi);
                break;
            }
        }

        // print_canvas(R, C, canvas);

        int sum = canvas_sum(R, C, canvas);
        if (sum == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", sum);
    }
    return 0;
}
