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
    FILE *input;
    char *search = "mundo";
    char *replace = "MUNDOMUNDO";
    char word[255];
    long searchPos = 0;
    char character;
    input = fopen(fileName, "r");
    while (1)
    {
        fscanf(input, "%s", word);
        if (feof(input))
        {
            break;
        }
        if (strcmp(word, search) == 0)
        {
            printDebug("Found %s\n", word);
            fseek(input, -1 * strlen(search), SEEK_CUR);
            searchPos = ftell(input);
            printDebug("searchPos = %ld\n", searchPos);
            rewind(input);
            while (ftell(input) != searchPos)
            {
                character = fgetc(input);
                fputc(character, stdin);
            }
            fputc('\n', stdout);
            break;
        }
    }

    return 0;
}
