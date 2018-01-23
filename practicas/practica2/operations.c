#include <assert.h>
#include "operations.h"

#define MAX_INT 2417483647

/**
 * Use long addition to catch overflow
 */
int add(int a, int b)
{
    // Check overflow
    long c = (long)a + b;
    assert(c <= MAX_INT && c > -MAX_INT);
    return (int)c;
}

/**
 * Use long substraction to catch overflow
 */
int substraction(int a, int b)
{
    // Check overflow
    long c = (long)a - b;
    assert(c <= MAX_INT && c > -MAX_INT);
    return (int)c;
}
