#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "messages.h"

#define MAX_STR_LENGTH 100
#define LANG "en"

typedef struct
{
    char *oprationName;
    int (*operation)(int, int);
} Operation;

int main()
{
    char operation[MAX_STR_LENGTH];
    int operatorOne, operatorTwo;
    int result;
    char **messages;

    if (!strcmp(LANG, "en"))
    {
        messages = message_EN;
    }
    if (!strcmp(LANG, "es"))
    {
        messages = message_ES;
    }

    printf("%s\n", messages[0]);
    scanf("%s", operation);
    printf("%s\n", operation);
    scanf("%d %d", &operatorOne, &operatorTwo);
    if (!strcmp(operation, "add"))
    {
        result = add(operatorOne, operatorTwo);
    }
    else if (!strcmp(operation, "substraction"))
    {
        result = substraction(operatorOne, operatorTwo);
    }
    else
    {
        printf("%s\n", messages[1]);
    }
    printf("%s: %d\n", messages[2], result);
    return 0;
}
