#include <stdio.h>
#include <string.h>

int strongPasswordChecker(char *s)
{
    int changes = 0, extra = 0, missing = 0;
    int len = strlen(s);
    printf("%d\n", len);
    int low = 1, up = 1, dig = 1;
    for (char *p = s; *p != '\0'; ++p)
    {
        if (low && (*p >= 'a' && *p <= 'z'))
        {
            low = 0;
        }
        if (up && (*p >= 'A' && *p <= 'Z'))
        {
            up = 0;
        }
        if (dig && (*p >= '0' && *p <= '9'))
        {
            dig = 0;
        }
    }
    if (len < 6)
    {
        missing = 6 - len;
        // printf("%d, %d, %d, %d\n", changes, low, up, dig);
        int rep = 1;
        char prev = '\0';
        for (char *p = s; *p != '\0'; ++p)
        {
            if (*p == prev && ++rep >= 3)
            {
                printf("%d, %d, %d, %d\n", changes, low, up, dig);
                if (low)
                    low = 0;
                else if (up)
                    up = 0;
                else if (dig)
                    dig = 0;
                if (missing > 0)
                {
                    --missing;
                    // --changes;
                }
                ++changes;
                rep = 0;
            }
            else if (*p != prev)
            {
                rep = 1;
            }
            prev = *p;
        }
        if (low && missing > 0)
        {
            low = 0;
            --missing;
            ++changes;
        }
        if (up && missing > 0)
        {
            up = 0;
            --missing;
            ++changes;
        }
        if (dig && missing > 0)
        {
            dig = 0;
            --missing;
            ++changes;
        }
        return changes + low + up + dig + missing;
    }
    else
    {
        int deletions = 0;
        extra = len - 20;
        int rep = 1;
        char prev = '\0';
        for (char *p = s; *p != '\0'; ++p)
        {
            if (*p == prev && ++rep >= 3)
            {
                printf("%d, %d, %d, %d, %d, %c\n", changes, low, up, dig, extra, *p);
                if (extra > 0)
                {
                    --extra;
                    ++deletions;
                    ++changes;
                    --rep;
                }
                else if (low)
                {
                    low = 0;
                    ++changes;
                    rep = 0;
                }
                else if (up)
                {
                    up = 0;
                    ++changes;
                    rep = 0;
                }
                else if (dig)
                {
                    dig = 0;
                    ++changes;
                    rep = 0;
                }
                else
                {
                    ++changes;
                    rep = 0;
                }
            }
            else if (*p != prev)
            {
                rep = 1;
            }
            prev = *p;
        }
        if (extra < 0)
            extra = 0;
        printf("%d, %d, %d, %d, %d\n", changes, low, up, dig, extra);
        return changes + low + up + dig + extra;
    }
    return 0;
}
