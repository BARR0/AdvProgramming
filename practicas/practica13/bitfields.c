#include <stdio.h>

#define LEAP_MASK 0b10000
#define PRIME_MASK 0b00100

typedef struct
{
    unsigned flags : 5;
    unsigned day : 5;
    unsigned month : 4;
    unsigned year;

} Date;

int main()
{
    Date today = {LEAP_MASK, 23, 4, 2018};
    printf("size of date = %ld\n", sizeof(Date));
    printf("%d/%d/%d\n", today.day, today.month, today.year);
    if (today.day ^ 23)
    {
        printf("No\n");
    }
    else
    {
        printf("YES\n");
    }
    today.flags = LEAP_MASK | PRIME_MASK;
    if (today.flags & (LEAP_MASK | PRIME_MASK) == LEAP_MASK | PRIME_MASK)
        printf("LEAP and PRIME\n");

    return 0;
}
