#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int compute_lettercount(string text);

int compute_wordcount(string text);

int compute_sentencecount(string text);

int compute_index(int lettercount, int wordcount, int sentencecount);

int main(void)

//ask for text
{
    string text = get_string("Text: ");

    int lettercount = compute_lettercount(text);

    int wordcount = compute_wordcount(text);

    int sentencecount = compute_sentencecount(text);

    int index = compute_index(lettercount, wordcount, sentencecount);
//compute grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
//count letters
int compute_lettercount(string text)
{
    int lettercount = 0;

    for (int i = 0, n = strlen(text); i < n; i += 1)

        if (text[i] >= 'A' && text[i] <= 'z')
        {
            text[i] = toupper(text[i]);
            lettercount += 1;
        }
    return lettercount;
}
//count words
int compute_wordcount(string text)
{
    int wordcount = 0;

    for (int i = 0, n = strlen(text); i < n; i += 1)

        if (text[i] == (' '))
        {
            wordcount += 1;
        }
    return wordcount + 1;
}
//count sentences
int compute_sentencecount(string text)
{
    int sentencecount = 0;

    for (int i = 0, n = strlen(text); i < n; i += 1)

        if (text[i] == ('.') || text[i] == ('?') || text[i] == ('!'))
        {
            sentencecount += 1;
        }
    return sentencecount;
}
//formula to calculate index from letters, words, sentences
int compute_index(int lettercount, int wordcount, int sentencecount)
{
    float per_100_words = wordcount;
    float L = (lettercount / per_100_words) * 100;
    float S = (sentencecount / per_100_words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
