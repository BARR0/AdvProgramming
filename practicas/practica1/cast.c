#include <stdio.h>

int main()
{
    int a = 4;
    int j;
    int *p;
    float f = 7.5;
    int max = ~0u >> 1;
    long d;
    int b = a + (int)f;
    float c = a * f;
    int arreglo[5] = {0, 2}; // EL resto se inicializan en 0

    d = (long)max * max;
    p = &a;
    *p = 7;
    p++;
    *p = 88;
    p = arreglo;

    for (int k = 0; k < sizeof(arreglo) / sizeof(arreglo[0]); k++)
    //                         ^ No usar apuntador
    {
        *p = 67;
        p++;
    }

    printf("a = %p, b = %d, j = %d, d = %ld\n", &a, b, j, d);
    printf("f = %f, c = %f\n", f, c);

    return 0;
}
