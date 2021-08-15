#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{   
    // < 2 arguments, kick back
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    //check if card = null, detect error if true
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)

    {
        printf("Error detected %s\n", argv[1]);
        return 1;
    }
    //need to set aside some memory for these variables(malloc)
    int jpeg_counter = 0;
    char file_name[8];
    unsigned char *buffer = malloc(512);
    FILE *JPEG;

    while (fread(buffer, 512, 1, card))
    {
        //found the new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if jpeg is already there, then close
            if (jpeg_counter > 0)
            {
                fclose(JPEG);
            }
            //create the new
            sprintf(file_name, "%03i.jpg", jpeg_counter);

            //open it
            JPEG = fopen(file_name, "w");

            //check if it was created or not

            if (JPEG == NULL)
            {
                fclose(card);
                free(buffer);
                printf("error %s", file_name);
                return 3;
            }

            jpeg_counter += 1;

        }

        //if a jpeg exists , write on the file that is currently open

        if (jpeg_counter > 0)
        {
            fwrite(buffer, 512, 1, JPEG);
        }
    }

    //  free the memory & close

    fclose(JPEG);
    fclose(card);
    free(buffer);
    return 0;
}

//fread (data, size, number, inptr);

