#include <stdio.h>
#include <stdbool.h>

#define Q1 0
#define Q2 1
#define Q3 2
#define Q4 3
#define Q5 4
#define Q6 5
#define Q7 6
#define QB -1
int TRANSITIONS[][] =  {
    {Q2, Q3, Q, Q1},
    {Q3, QB, Q, QB},
    {Q3, QB, Q, Q4},
    {QB, QB, Q, Q4},
    {Q, Q, Q, Q}
};

bool isNumber(char *s)
{
    char *n;
    int state = Q1;
    for (n = s; n != '\0'; ++n)
    {
        if (state == QB)
            return false;

        if (*s >= '0' && *s <= '9')
            state = TRANSITIONS[state][0];
        else if (*s == '.')
            state = TRANSITIONS[state][1];
        else if (*s == 'e')
            return isNumber(++s);
        else if (*s == ' ')
            state = TRANSITIONS[state][2];
        else if (*s == '+' || *s == '-')
            state = TRANSITIONS[state][3];
        else
            return false;
    }
    return state == Q4;
}
