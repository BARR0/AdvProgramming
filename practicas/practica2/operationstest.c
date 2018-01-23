#include <stdio.h>
#include "operations.h"

void printTestMessage(int, char *, char *);
int testAddition(void);
int testSubstraction(void);

int main(void)
{
    printTestMessage(testAddition(),
                     "add test passed",
                     "add test failed");

    printTestMessage(testSubstraction(),
                     "substraction test passed",
                     "substraction test failed");
    return 0;
}

void printTestMessage(int condition, char *messagePassed, char *messageFailed)
{
    if (condition)
    {
        printf("%s\n", messagePassed);
    }
    else
    {
        printf("%s\n", messageFailed);
    }
}

int testAddition(void)
{
    int a = 5;
    int b = 7;

    int result = add(a, b);
    int expected = a + b;

    return result == expected;
}

int testSubstraction(void)
{
    int x = 5;
    int y = 7;

    int result2 = substraction(x, y);
    int expected2 = x - y;

    return result2 == expected2;
}
