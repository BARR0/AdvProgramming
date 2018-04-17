#include <stdio.h>
#include <omp.h>

int main()
{
    int a[20000];
    int b[20000];
    int c[20000];
    int chunk = 100;
    int j;

    for (int i = 0; i < 20000; ++i)
    {
        a[i] = i;
        b[i] = 2 * i;
    }
    #pragma omp parallel shared(a, b, c, chunk) private(j)
    {
        #pragma omp for schedule shared(dynamic, chunk) nowait
        for (j = 0; j < 20000; ++j)
        {
            printf("%d\n", j);
            c[i] = a[i] + b[i];
        }
    }

    return 0;
}
