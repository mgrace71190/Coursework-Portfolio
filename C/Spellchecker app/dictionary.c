// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>
#include <cs50.h>
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

unsigned int hashed;
unsigned int word_counter;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //convert word to hash value
    hashed = hash(word);
    //point to linked list
    node *cursor = table[hashed];

    //cycle through the list
    while (cursor != NULL)
    {
        //check if the word matchs
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }
        //go to next node
        cursor = cursor -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}
// plan is to open file, read strings, create new node, hash the word to get hash value, insert node
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    //open
    FILE *dict_file = fopen(dictionary, "r");
    //if no file, kick back 'false'
    if (dict_file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    //seach for beginning words
    while (fscanf(dict_file, "%s", word) != EOF)
    {
        //set aside memory
        node *n = malloc(sizeof(node));
        //if mallocis null, kick back false
        if (n == NULL)
        {
            return false;
        }
        strcpy(n -> word, word);
        //convert word to hash value
        hashed = hash(word);
        //point to next node

        //new pointer
        n -> next = table[hashed];
        //set new pointer
        table[hashed] = n;
        //word counter
        word_counter += 1;
    }
    fclose(dict_file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_counter > 0)
    {
        return word_counter;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //cycle through all the cats
    for (int i = 0; i < N; i += 1)
    {
        //point the cursor to a bucket
        node *cursor = table[i];

        //if the cursor isnt NULL, free it
        while (cursor)
        {
            //make a tmp
            node *tmp = cursor;
            //go to next node
            cursor = cursor -> next;
            //free the tmp
            free(tmp);
        }
        //account for NULL cursor
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}