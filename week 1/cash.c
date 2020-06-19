#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    float cent = get_float("Change owed: ");
    while (cent < 0) 
    {
        cent = get_float("Change owed: ");
    }

    int count = 0;
    int cents = roundf(cent * 100);

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
        count++;
    }

    printf("%d\n", count);
}