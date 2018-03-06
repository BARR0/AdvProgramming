#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "hash.h"

bool is_letter(char s)
{
    return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z');
}

char *get_word(char *line)
{
    int len = 0;

    char *s;
    for (s = line; is_letter(*s); ++s)
    {
        ++len;
    }

    char *word = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; ++i)
    {
        word[i] = tolower(line[i]);
    }
    word[len] = '\0';

    return word;
}

void word_count(char *words)
{
    HashInt table;
    hashInit(&table, 20);
    char *s;
    for (s = words; *s != '\0'; ++s)
    {
        if (is_letter(*s))
        {
            char *word = get_word(s);
            int *result = hashGet(&table, word);
            if (result == NULL)
            {
                hashInsert(&table, word, 1);
            }
            else
            {
                ++(*result);
                free(word);
            }

            while (is_letter(*s))
            {
                ++s;
            }
        }
    }

    for (int i = 0; i < table.size; ++i)
    {
        for (int j = 0; j < table.data[i].length; ++j)
        {
            char *word = table.data[i].elements[j].key;
            int value = table.data[i].elements[j].value;
            if(word != NULL)
            {
                printf("%s\t%d\n", word, value);
            }
        }
    }
}

int main()
{
    word_count("Hola como estas. hola como estAS.");
}
