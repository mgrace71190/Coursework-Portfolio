#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //ask the user for amount of cash
    float change;
    int coin_counter = 0;
    do
    {
        change = get_float("Change owed:");
    }
    while (change <= 0);

    //convert "change" to units of cents only
    int cents = round(change * 100);

    //calculate minimum number of coins needed
    //cycle through 25, 10, 5, 1 cent coins
    //subtract each possible coin as you progress to get min number of coins
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }

        else if (cents >= 5)
        {
            cents -= 5;
        }
        else if (cents >= 1)
        {
            cents -= 1;
        }
        coin_counter += 1;

    }
    printf("%i\n", coin_counter);

}


