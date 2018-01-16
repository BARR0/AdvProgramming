#include <stdio.h>

int swap_no(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;
    return 0;
}

int swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return 0;
}

int main()
{
    int j = 27, k = 34;
    swap_no(j, k);
    printf("%d : %d\n", j, k);
    swap(&j, &k);
    printf("%d : %d\n", j, k);
}
