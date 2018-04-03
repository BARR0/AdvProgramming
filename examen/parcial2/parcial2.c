/**
    To reverse word by word, we need to know where each word ends and begins. For most cases this
will be the character ‘ ‘, but others will have a new line or null. Once we have defined what
a word is, we can start by reading the amount of lines to read and treating each one
individually.
    When a new line is received, the program starts from the end and moves to the beginning.
Since all words are separated by spaces, each space tells the program that a word begins one
character forwards, so we send a pointer to the beginning of the word to a function that
prints a word but stops at any character that isn’t a letter. When the program reaches the
start of the line, we just manually print the first word since that one isn’t after a space.
Now all words have been printed starting from the last one.
    The code can be evaluated by each line that is reversed. If the length of the line is N,
the program fist moves N steps to the last character. Then, it traverses the line backwards
another N steps, printing a word for each space. This means going forwards again. Thankfully,
after the forwards and backwards pass, each character is visited at most one more time when a
word is being printed. In total, there were 3N steps for each line. The program evaluates
many lines but the complexity stays the same, just accounting for the total length of all
lines. The running time is O(N).
**/

#include <stdio.h>

#define MAX 12 * 100

void print_word(char *c)
{
    while((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
    {
        printf("%c", *c);
        ++c;
    }
}

void reverse_words(char *line)
{
    char *c;
    for (c = line; *c != '\0'; ++c);
    while(c >= line)
    {
        if(*c == ' ')
        {
            print_word(c + 1);
            printf(" ");
        }
        --c;
    }
    print_word(line);
    printf("\n");

}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        char line[MAX];
        scanf(" %[^\n]", line);
        reverse_words(line);
    }
}
