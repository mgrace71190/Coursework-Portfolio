#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{   
    //if there aren't 2 arguments, stop (ie ./caesar & the key number)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //the key is the second argument (the number after ./caesar)
    else
    {
        string key = argv[1];

        for (int i = 0; i < strlen(key); i += 1)
        {
            if ((key[i] >= '0' && key[i] <= '9') == 0)
            {
                printf("Usage: ./caesar key\n");

                return 1;
            }

        }
        //convert string to integer
        int ci = atoi(key);

        string text = get_string("Text:");

        for (int i = 0; i < strlen(text); i += 1)
        {
            if (isupper(text[i]))
            {
                text[i] = (text[i] - 65);
                text[i] = (text[i] + ci) % 26;
                text[i] = (text[i] + 65);
            }
            //if the character is lower, subtreact 97 (ASCII)
            if (islower(text[i]))
            {
                text[i] = (text[i] - 97);
                text[i] = (text[i] + ci) % 26;
                text[i] = (text[i] + 97);
            }
            if (isalpha(text[i]) == 0)
            {
                text[i] = text[i];
            }
            //ci = (pi + k) % 26

        }
        printf("ciphertext: %s", text);
        printf("\n");
    }
}

