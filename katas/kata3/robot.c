#include <stdbool.h>
#include <stdio.h>

bool judgeCircle(char *moves)
{
    char *c;
    int i = 0, j = 0;
    for (c = moves; *c != '\0'; ++c)
    {
        // printf("%c\n", *c);
        switch (*c){
        case 'R':
            ++i;
            break;
        case 'L':
            --i;
            break;
        case 'U':
            ++j;
            break;
        case 'D':
            --j;
            break;
        }
    }
    return i == 0 && j == 0;
}

int main ()
{
    char *s = "UDUD";
    printf("%d\n", judgeCircle(s));
    return 0;
}
