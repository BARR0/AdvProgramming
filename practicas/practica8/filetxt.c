#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define printDebug(...)                                   \
    do                                                    \
    {                                                     \
        char *isDebug = getenv("DEBUG");                  \
        if (isDebug != NULL && !strcasecmp(isDebug, "y")) \
        {                                                 \
            fprintf(stderr, __VA_ARGS__);                 \
        }                                                 \
    } while (0);

int main()
{
    char *fileName = "output.txt";
    FILE *output;
    int character;
    output = fopen(fileName, "a");
    printDebug("output = %p\n", output);
    do
    {
        character = fgetc(stdin);
        if (feof(stdin))
        {
            break;
        }
        fputc(character, output);
    } while (!feof(stdin));
    
    fclose(output);
    return 0;
}