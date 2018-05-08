#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

unsigned long long POWERS[] =
{
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000,
    100000000000,
    1000000000000,
    10000000000000,
    100000000000000,
    1000000000000000,
    10000000000000000,
    100000000000000000,
    1000000000000000000
};

bool isfav(unsigned long long L, unsigned long long *favs, int *digits, int N)
{
    while (L)
    {
        for (int i = 0; i < N; ++i)
        {
            if (L % POWERS[digits[i]] == favs[i])
                return true;
        }
        L /= 10;
    }
    return false;
}

int main()
{
    unsigned long long L, R, K;
    int N;
    scanf("%llu %llu %llu %d", &L, &R, &K, &N);
    unsigned long long favs[N];
    int digits[N];
    for (int i = 0; i < N; ++i)
    {
        scanf("%llu", favs + i);
        digits[i] = floor(log10l(favs[i])) + 1;
        // printf("%llu", favs[i]);
    }

    for (; L <= R; ++L)
    {
        // printf("%llu\n", L);
        if (isfav(L, favs, digits, N) && --K == 0)
        {
            printf("%llu\n", L);
            return 0;
        }
    }
    printf("no such number\n");
    return 0;
}
