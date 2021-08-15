#include "helpers.h"
#include <math.h>
//gs = grayscale
//h = height array
//w = width array
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gs;

    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < width; w += 1)
        {
            gs = round((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0);

            image[h][w].rgbtRed = gs;
            image[h][w].rgbtGreen = gs;
            image[h][w].rgbtBlue = gs;
        }
    }
}
int stopoverflow(int RGB)
{
    if (RGB > 255)
    {
        return 255;
    }
    else
    {
        return RGB;
    }
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed;
    int originalGreen;
    int originalBlue;
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < width; w += 1)
        {
            originalRed = image[h][w].rgbtRed;
            originalGreen = image[h][w].rgbtGreen;
            originalBlue = image[h][w].rgbtBlue;

            sepiaRed = stopoverflow(round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue));
            sepiaGreen = stopoverflow(round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue));
            sepiaBlue = stopoverflow(round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue));

            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temparray[3];

    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < width / 2; w += 1)
        {
            temparray[0] = image[h][w].rgbtRed;
            temparray[1] = image[h][w].rgbtGreen;
            temparray[2] = image[h][w].rgbtBlue;

            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;
            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;

            image[h][width - w - 1].rgbtRed = temparray[0];
            image[h][width - w - 1].rgbtGreen = temparray[1];
            image[h][width - w - 1].rgbtBlue = temparray[2];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int totalR;
    int totalG;
    int totalB;
    float tracker;

    RGBTRIPLE temp_image[height][width];

    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < width; w += 1)
        {
            totalR = 0;
            totalG = 0;
            totalB = 0;
            tracker = 0;

            for (int a = -1; a < 2; a += 1)
            {
                if (h + a < 0 || h + a > height - 1)
                {
                    continue;
                }

                for (int b = -1; b < 2; b += 1)
                {
                    if (w + b < 0 || w + b > width - 1)
                    {
                        continue;
                    }

                    totalR += image[h + a][w + b].rgbtRed;
                    totalG += image[h + a][w + b].rgbtGreen;
                    totalB += image[h + a][w + b].rgbtBlue;
                    tracker += 1;
                }
            }

            temp_image[h][w].rgbtRed = round(totalR / tracker);
            temp_image[h][w].rgbtGreen = round(totalG / tracker);
            temp_image[h][w].rgbtBlue = round(totalB / tracker);
        }
    }

    for (int h = 0; h < height; h += 1)
    {
        for (int w = 0; w < width; w += 1)
        {
            image[h][w].rgbtRed = temp_image[h][w].rgbtRed;
            image[h][w].rgbtGreen = temp_image[h][w].rgbtGreen;
            image[h][w].rgbtBlue = temp_image[h][w].rgbtBlue;

        }
    }
}

